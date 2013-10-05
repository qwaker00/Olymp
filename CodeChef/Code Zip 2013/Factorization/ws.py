#!/usr/bin/python
import sys
from getopt import getopt
WHITESPACE = 0
FIZZBUZZ = 1
def main(args):
    style = WHITESPACE
    opts, files = getopt(args, '', ['fizzbuzz', 'compile-only'])
    compile_only = False
    for o, v in opts:
        if o == '--fizzbuzz':
            style = FIZZBUZZ
        if o == '--compile-only':
            compile_only = True
    for f in files:
        src = open(f).read()
        if style == FIZZBUZZ:
            src = translate_fizzbuzz(src)
            if compile_only:
                print src
                return 0
        vm = VirtualMachine()
        try:
            vm.execute(src)
        except:
            print 'Error:', f
            print '  [Stack]', vm._stack
            print '  [Heap]', vm._heap
            print '  [Label]', vm._labels
            print '  [Pos]', vm._pos
            print '  [Code]', vm._code[vm._pos-10:vm._pos+10]
            raise

SPACE = ' '
TAB = '\t'
LF = '\n'
class VirtualMachine(object):
    def __init__(self):
        self._state = None
        self._prev = None
        self._is_label_phase = False
        self._searching_label = None
        self._code = []
        self._pos = 0
        self._labels = {}
        self._call_stack = []
        self._stack = []
        self._heap = {}

    def execute(self, source, cout=None, cin=None):
        if cout:
            self.cout = cout
        else:
            self.cout = sys.stdout
        if cin:
            self.cin = cin
        else:
            self.cin = sys.stdin
        src = tokenize(source)
        self._code = tokenize(source)
        self._length = len(self._code)
        self._pos = 0
        while not self.eop:
            token = self.read()
            self._evaluate(token)

    def _evaluate(self, token):
        try:
            if self._state is not None:
                self._state.run(token)
            else:
                if self._prev is None and token == SPACE:
                    self._state = StackManipulation(self)
                elif self._prev is None and token == LF:
                    self._state = FlowControl(self)
                else:
                    if self._prev is None:
                        self._prev = token
                    elif self._prev == TAB and token == SPACE:
                        self._state = Arithmetic(self)
                        self._prev = None
                    elif self._prev == TAB and token == TAB:
                        self._state = HeapAccess(self)
                        self._prev = None
                    elif self._prev == TAB and token == LF:
                        self._state = IO(self)
                        self._prev = None
                    else:
                        assert False, 'Invalid token %s, at %d' % (token, self.program._pos-1)
        except:
            raise

    @property
    def is_label_phase(self):
        return self._is_label_phase

    @property
    def eop(self):
        return self._pos >= self._length

    def read(self):
        r = self._code[self._pos]
        self._pos += 1
        return r

    def label(self, l):
        if self.is_label_phase:
            if self._searching_label == l:
                self._is_label_phase = False
                self._searching_label = None
        self._labels[l] = self._pos

    def call_sub(self, l):
        if self.is_label_phase: return
        if l not in self._labels:
            self._call_stack.append(self._pos)
            self._is_label_phase = True
            self._searching_label = l
            return
        self._call_stack.append(self._pos)
        self._pos = self._labels[l]
        
    def end_sub(self):
        if self.is_label_phase: return
        p = self._call_stack.pop(-1)
        self._pos = p

    def jump(self, l):
        if self.is_label_phase: return
        try:
            if l not in self._labels:
                self._is_label_phase = True
                self._searching_label = l
                return
            self._pos = self._labels[l]
        except:
            print self._labels
            raise

    def jump_if_zero(self, l):
        if self.is_label_phase: return
        v = self.top()
        self.pop()
        if v == 0:
            self.jump(l)

    def jump_if_neg(self, l):
        if self.is_label_phase: return
        v = self.top()
        self.pop()
        if v < 0:
            self.jump(l)

    def exit(self):
        if self.is_label_phase: return
        self._pos = self._length

    def push(self, n):
        if self.is_label_phase: return
        self._stack.append(n)

    def dup_top(self):
        if self.is_label_phase: return
        self._stack.append(self._stack[-1])

    def dup_nth(self, n):
        if self.is_label_phase: return
        self._stack.append(self._stack[-n - 1])

    def swap(self):
        if self.is_label_phase: return
        t = self._stack.pop(-1)
        s = self._stack.pop(-1)
        self._stack.append(t)
        self._stack.append(s)

    def pop(self):
        if self.is_label_phase: return
        self._stack.pop(-1)

    def slide(self, n):
        if self.is_label_phase: return
        top = self._stack.pop(-1)
        for i in range(n):
            self._stack.pop(-1)
        self._stack.append(top)

    def store(self):
        if self.is_label_phase: return
        value = self._stack.pop(-1)
        addr = self._stack.pop(-1)
        self._heap[addr] = value

    def retrieve(self):
        if self.is_label_phase: return
        addr = self._stack.pop(-1)
        value = self._heap[addr]
        self._stack.append(value)

    def top(self):
        if self.is_label_phase: return
        return self._stack[-1]




import re

def tokenize(src):
    r = []
    skip = False
    for t in src:
        if t in ('\t', '\n', ' '):
            r.append(t)
    return r

def translate_fizzbuzz(src):
    ws = re.compile('\s')
    tokens = ws.split(src)
    r = []
    for t in map(str.lower, tokens):
        if t == 'fizz':
            r.append(SPACE)
        elif t == 'buzz':
            r.append(TAB)
        elif t == 'fizzbuzz':
            r.append(LF)
    return ''.join(r)

NUMBER = 0
LABEL = 1

class Dispatcher(object):
    def __init__(self, state, command_map):
        self._command_map = command_map
        self._command = None
        self._state = state
        self._op = ''

    def run(self, token):
        if self._command is not None:
            self._command.feed(token)
            if not self._command.requires_param:
                self._command.run()
                self._state.end()
        else:
            self._op += token
            if self._op in self._command_map:
                args = self._command_map[self._op]
                self._command = Command(self._state, args[0], args[1])
                self._op = ''
                if not self._command.requires_param:
                    self._command.run()
                    self._state.end()

class Command(object):
    def __init__(self, state, func, param_type):
        self._func = func
        self._param_type = param_type
        self._param = None
        self._tokens = []
        self._state = state
    
    def feed(self, token):
        if self._param_type == LABEL:
            if token == LF:
                self._param = ''.join(self._tokens)
            else:
                self._tokens.append(token)
        else:
            if token == LF:
                sign = self._tokens[0]
                nums = ''.join(self._tokens[1:]).replace(SPACE, '0').replace(TAB, '1')
                if not nums: nums = '0'
                number = int(nums, 2)
                if sign == TAB:
                    self._param = -number
                else:
                    self._param = number
            else:
                self._tokens.append(token)

    def run(self):
        if self._param_type is None:
            self._func()
        else:
            self._func(self._param)

    @property
    def requires_param(self):
        return self._param_type is not None and self._param is None

class State(object):
    def __init__(self, vm):
        self._vm = vm
        self._dispatcher = None

    def run(self, token):
        self._dispatcher.run(token)

    def end(self):
        self._vm._state = None
    
    @property
    def vm(self):
        return self._vm

class StackManipulation(State):
    def __init__(self, vm):
        State.__init__(self, vm)
        self._dispatcher = Dispatcher(self, {
            SPACE: (vm.push, NUMBER),
            LF+SPACE: (vm.dup_top, None),
            TAB+SPACE: (vm.dup_nth, NUMBER),
            LF+TAB: (vm.swap, None),
            LF+LF: (vm.pop, None),
            TAB+LF: (vm.slide, NUMBER)
        })

class FlowControl(State):
    def __init__(self, vm):
        State.__init__(self, vm)
        self._dispatcher = Dispatcher(self, {
            SPACE*2: (vm.label, LABEL),
            SPACE+TAB: (vm.call_sub, LABEL),
            SPACE+LF: (vm.jump, LABEL),
            TAB+SPACE: (vm.jump_if_zero, LABEL),
            TAB+TAB: (vm.jump_if_neg, LABEL),
            TAB+LF: (vm.end_sub, None),
            LF+LF: (vm.exit, None),
        })

    def run(self, token):
        self._dispatcher.run(token)

class IO(State):
    def __init__(self, vm):
        State.__init__(self, vm)
        self._dispatcher = Dispatcher(self, {
            SPACE*2: (self.output_char, None),
            SPACE+TAB: (self.output_int, None),
            TAB+SPACE: (self.read_char, None),
            TAB*2: (self.read_int, None),
        })

    def output_char(self):
        if self.vm.is_label_phase: return
        self.vm.cout.write(chr(self.vm.top()))
        self.vm.pop()

    def output_int(self):
        if self.vm.is_label_phase: return
        self.vm.cout.write(str(self.vm.top()))
        self.vm.pop()

    def read_char(self):
        if self.vm.is_label_phase: return
        addr = self.vm.top()
        self.vm.pop()
        c = self.vm.cin.read(1)
        self.vm._heap[addr] = c
    
    def read_int(self):
        if self.vm.is_label_phase: return
        addr = self.vm.top()
        self.vm.pop()
        buff = ''
        while True:
            c = self.vm.cin.read(1)
            if c == '\n' or c == '\r':
                break
            buff+=c
        c = int(buff)
        self.vm._heap[addr] = c
    
class HeapAccess(State):
    def __init__(self, vm):
        State.__init__(self, vm)
        self._dispatcher = Dispatcher(self, {
            SPACE: (vm.store, None),
            TAB: (vm.retrieve, None),
        })

import operator
class Arithmetic(State):
    def __init__(self, vm):
        State.__init__(self, vm)
        self._dispatcher = Dispatcher(self, {
            SPACE*2: (self.op(operator.add), None),
            SPACE+TAB: (self.op(operator.sub), None),
            SPACE+LF: (self.op(operator.mul), None),
            TAB+SPACE: (self.op(operator.div), None),
            TAB*2: (self.op(operator.mod), None),
        })

    def op(self, f):
        def _op():
            if self.vm.is_label_phase: return
            ri = self.vm.top()
            self.vm.pop()
            le = self.vm.top()
            self.vm.pop()
            rs = f(le, ri)
            self.vm.push(rs)
        return _op



if __name__ == '__main__':
    main(sys.argv[1:])

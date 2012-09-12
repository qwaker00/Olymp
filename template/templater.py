import sys, os

if len(sys.argv) < 3:
    print 'Usage: templater.py "filename.cpp" "my\\template\\dir\\"'
    sys.exit(1)

src_filename = sys.argv[1]
template_dir = sys.argv[2]

includes = []
template_list = []
body = []
for s in open(src_filename):
    if s.strip().startswith('#include'):
        includes.append(s)
    elif s.strip().startswith('#template'):
        template_list.append(s.strip())
    else:
        body.append(s)

def add_template(tname, tfile, inc, body):
    for s in body:
        if s.strip().startswith('// #template ' + tname):
            return
    temp_body = []
    for s in open(tfile):
        if s.strip().startswith('#pragma'):
            pass
        elif s.strip().startswith('#include'):
            inc_name = s[8:].strip()
            if inc_name[0] == '"' and inc_name[-1] == '"':
                add_template(inc_name[1:-1], os.path.join(os.path.dirname(tfile), inc_name[1:-1]), inc, body)
            else:
                ti = s.strip()[8:].strip()
                ti = ti[1:-1]
                for i in inc:
                    ii = i.strip()[8:].strip()
                    ii = ii[1:-1]
                    if ti == ii:
                        break
                else:
                    inc.append(s)
        else:
            temp_body.append(s)
    while len(temp_body) > 0 and len(temp_body[0].strip()) == 0:
        del temp_body[0]
    while len(temp_body) > 0 and len(temp_body[-1].strip()) == 0:
        del temp_body[-1]

    body.insert(0, '// end of ' + tname + '\n')
    for s in reversed(temp_body):
        body.insert(0, s)
    body.insert(0, '// #template ' + tname + ': do not remove this line\n')

while len(body) > 0 and len(body[0].strip()) == 0: del body[0]
while len(body) > 0 and len(body[-1].strip()) == 0: del body[-1]

for t in template_list:
    template_file = os.path.join(template_dir, t[9:].strip())
    add_template(t[9:].strip(), template_file, includes, body)

result = open(src_filename, 'w')
result.write(''.join(includes))
result.write('\n')
result.write(''.join(body))

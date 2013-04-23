#pragma once
#include "random.h"

namespace qwaker {

template<typename T = int>
class treap_array {
public:
    typedef T value_type;
    
    treap_array(size_t n = 0) : root(NULL) {
        root = __init_node(n);
    }

    treap_array(treap_array& a, treap_array& b) {
        __merge(a.root, b.root, root);
    }

    ~treap_array() {
        if (root) {
            delete root;
        }
    }

    void clear() {
        if (root) {
            delete root;
            root = NULL;
        }
    }

    size_t size() {
        return __size(root);
    }

    value_type& operator[](size_t n) {
        assert(n < __size(root));
        return __find_by_index(n);
    }

    const value_type& operator[](size_t n) const {
        assert(n < __size(root));
        return __find_by_index(n);
    }

    treap_array& split(size_t pivot, treap_array& partB) {
        assert(this != &partB);        
        __split(root, pivot, root, partB.root);
        return *this;
    }

    treap_array& split(size_t pivot, treap_array& partA, treap_array& partB) {
        assert(&partA != &partB);
        if (this != &partA) partA.clear();
        if (this != &partB) partB.clear();
        __split(root, pivot, partA.root, partB.root);
        if (this != &partA && this != &partB) root = NULL;
        return *this;
    }

    treap_array& merge(treap_array& partB) {
        assert(this != &partB);
        __merge(root, partB.root, root);
        partB.root = NULL;
        return *this;
    }

    treap_array& merge(treap_array& partA, treap_array& partB) {
        assert(&partA != &partB);
        if (this != &partA && this != &partB) clear();
        __merge(partA.root, partB.root, root);
        if (this != &partA) partA.root = NULL;
        if (this != &partB) partB.root = NULL;
        return *this;
    }

    void insert(const value_type& x) {
        Node* newnode = new Node(x);
        __merge(root, newnode, root);
    }
    void insert(const value_type& x, size_t n) {
        assert(n <= __size(root));
        Node *p1, *p2, *newnode = new Node(x);
        __split(root, n, p1, p2);
        __merge(p1, newnode, p1);
        __merge(p1, p2, root);
    }

    void erase(size_t n) {
        assert(n < __size(root));
        Node *p1, *p2, *newnode;
        __split(root, n, p1, p2);
        __split(p2, 1, newnode, p2);
        __merge(p1, p2, root);
    }

    void cut(size_t l, size_t r, treap_array& seg) {
        if (&seg != this) seg.clear();
        assert(l <= r);
        assert(r <= __size(root));
        Node *p1, *p2;
        __split(root, l, p1, p2);
        __split(p2, r - l, seg.root, p2);
        if (&seg != this) __merge(p1, p2, root);
    }

protected:
    struct Node {
        value_type x;
        size_t size;
        Node *left, *right;

        Node(const value_type& x = value_type()) : x(x), size(1), left(NULL), right(NULL) { };
        ~Node() {
            if (left) delete left;
            if (right) delete right;
        }
    };
    Node* root;

    explicit treap_array(Node* root) : root(root) { }
    treap_array(const treap_array& x) { }

    inline size_t __size(Node* root) {
        return root ? root->size : 0;
    }

    Node* __init_node(size_t n) {
        if (!n) return NULL;
        Node* root = new Node();
        root->left = __init_node(n >> 1);
        root->right = __init_node(n - (n >> 1) - 1);
        root->size = n;
        return root;
    }

    value_type& __find_by_index(size_t n) {
        Node* current = root;
        while (current) {
            size_t leftsize = __size(current->left);
            if (n < leftsize) {    
                current = current->left;
                continue;
            }
            if (n == leftsize) {
                return current->x;
            }
            current = current->right;
            n -= leftsize + 1;
        } 
        throw "Bad implementation";
    }

    void __split(Node* root, size_t pivot, Node*& left, Node*& right) {
        if (!root) return void(left = right = NULL);
        size_t leftsize = __size(root->left);
        if (pivot <= leftsize) {
            __split(root->left, pivot, left, root->left);
            right = root;
        } else {
            __split(root->right, pivot - leftsize - 1, root->right, right);
            left = root;            
        }
       root->size = __size(root->left) + __size(root->right) + 1;
    }

    void __merge(Node* left, Node* right, Node*& root) {
        if (!left) return void(root = right);
        if (!right) return void(root = left);
        if (flip_coin(left->size, right->size)) {
            __merge(left->right, right, left->right);
            root = left;
        } else {
            __merge(left, right->left, right->left);
            root = right;
        }
        root->size = __size(root->left) + __size(root->right) + 1;
    }
};

}

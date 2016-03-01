#include <cstdio>
using namespace std;

struct treap {
    int x, y, sz;
    treap *l, *r;
};

int cnt(treap *t) {return t ? t->sz : 0;}
void updt(treap *t) {if (t) t->sz = 1 + cnt(t->r) + cnt(t->l);}

void split(treap* t, int k, treap *&l, treap *&r) {
    if (!t) l = r = NULL;
    else if (k <= t->x) split(t->l, k, l, t->l), r = t;
    else split(t->r, k, t->r, r), l = t;
}

void merge(treap *&t, treap *l, treap *r) {
    if (!l || !r) t = l ? l : r;
    else if (l->y <= r->y) merge(r->l, l, r->l), t = r;
    else merge(l->r, l->r, r), t = l;
}

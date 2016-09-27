struct Treap {
    int key, pri , val ,sz ,  lazy;
    Treap *l, *r;
    Treap(int _key, int _val): key(_key) , val(_val), pri(rand()) , sz(1), lazy(0), l(NULL), r(NULL){ }
};
inline int Size(Treap* t)
{
    return t?t->sz:0;
}
inline void Pull(Treap* t)
{
    t->sz = Size(t->l) + Size(t->r) + 1;
}
void Push(Treap* t)
{
    t->val += t->lazy;
    if (t->l)t->l->lazy += t->lazy;
    if (t->r)t->r->lazy += t->lazy;
    t->lazy = 0;
}
Treap* Merge(Treap* a, Treap* b)
{
    if (!a || !b) return a ? a : b;
    if (a->pri > b->pri) {
        a->r = Merge(a->r, b); Pull(a); return a;
    } else {
        b->l = Merge(a, b->r);Pull(b);return b;
    }
}
void Split(Treap* t, int k, Treap*& a, Treap*& b)
{
    if (!t) a = b = NULL;
    else {
      if (t->key <= k) {
            a = t; Split(t->r, k, a->r, b);Pull(a);
        } else {
            b = t; Split(t->l, k, a, b->l); Pull(b);
        }
    }
}
Treap* Del(Treap* t, int k) //delete all key=k
{
    if (t->key == k) {return Merge(t->l, t->r);
    } else if (k < t->key) { t->l = Del(t->l, k); return t;
    } else {  t->r = Del(t->r, k); return t;
    }
}
Treap* insert(Treap* t, int key,int val)
{
    Treap *tl, *tr;
    Split(t, key, tl, tr);
    Treap  tmp(key,val);
    Treap *ans = &tmp;
    Merge(ans,tl); Merge(ans,tr);
    return ans;
}

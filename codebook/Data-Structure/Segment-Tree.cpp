struct Node{
    int value;
    Node *lc,*rc;
    Node(){value = 0;lc = rc = NULL;}
    void pull(){ value = lc->value+rc->value; }
};
int v[N];
Node* build(int L,int R){
    Node *node = new Node();
    if(L == R){
        node->value = v[L];
        return node;
    }
    int mid = (L+R)>>1;
    node->lc = build(L,mid);
    node->rc = build(mid+1,R);
    node->pull();
    return node;
}
void modify(Node *node,int L,int R,int i,int d){
    if(L == R){
        node->value += d;
        return;
    }
    int mid = (L+R)>>1;
    if(i<=mid)modify(node->lc,L,mid,i,d);
    else modify(node->rc,mid+1,R,i,d);
    node->pull();
}
int query(Node* node,int L,int R,int ql,int qr){
    if(ql > R || qr < L)return 0;
    if(ql <= L && R <= qr)return node->value;
    int mid = (L+R)>>1;
    return query(node->lc,L,mid,ql,qr)+query(node->rc,mid+1,R,ql,qr);
}

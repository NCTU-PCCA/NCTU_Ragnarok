#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000;
int size[MAXN], pre[MAXN], son[MAXN], dep[MAXN];
vector<int> E[MAXN];
struct Node{ // segmnet tree with lazy tag;
    Node * l ,* r ;
    int v,lazy;
}*root;
//1-based;
int dfs(int x, int fa)
{
    size[x] = 1;
    int max_v = INT_MIN;
    dep[x] = dep[fa] + 1;
    pre[x]=fa;
    for(auto &v:E[x]){
        size[x] += dfs(v, x);
        if (size[v] > max_v) {
            max_v = size[v];
            son[x] = v;
        }
    }
    return size[x];
}
int no,pos[MAXN],top[MAXN];
int repos(int x ,int fa,int tp){
    pos[x]=++no;
    top[x]=tp;
    if(son[x]) repos(son[x],x,tp);
    for(auto &v:E[x]){
        if(v!=son[x] && v!=fa) repos(v,x,v);
    }
}
// 1-based segment tree
void update_seg(Node* root,int l,int r ,int ql,int qr ,int v){
    ;
}
void query_seg(Node* root,int l,int r ,int ql,int qr){
    ;
}
void update(int x, int y,int v)
{
    while(top[x]!=top[y]){
        if(dep[x]<dep[y]) swap(x,y);
        update_seg(root,1,MAXN,pos[top[x]],pos[x],v);
        x=pre[top[x]];
    }
    update_seg(root,1,MAXN,min(pos[x],pos[y]),max(pos[x],pos[y]),v);
}
//query from x to y
void query(int x ,int y){
    int ans;
    while(top[x]!=top[y]){
        if(dep[x]<dep[y]) swap(x,y);
        ans+=query_seg(root,1,MAXN,pos[top[x]],pos[x]);
        x=pre[top[x]];
    }
    ans+=query_seg(root,1,MAXN,min(pos[x],pos[y]),max(pos[x],pos[y]));

}

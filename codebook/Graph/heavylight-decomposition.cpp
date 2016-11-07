#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000;
int size[MAXN], pre[MAXN], son[MAXN], dep[MAXN];
vector<int> E[MAXN];
struct Node{
    Node * l ,* r ;
    int v;
}*root;
int dfs(int x, int fa)
{
    size[x] = 1;
    int max_v = INT_MIN;
    dep[x] = dep[fa] + 1;
    pre[x]=fa;
    for (int i = 0; i < E[x].size(); i++) {
        int v = E[x][i];
        size[x] += dfs(v, x);
        if (size[v] > max_v) {
            max_v = size[v];
            son[x] = v;
        }
    }
}
int no,pos[MAXN],top[MAXN];
int repos(int x ,int tp){
    pos[x]=++no;
    top[x]=tp;
    if(son[x]) repos(son[x],tp);
    for(int i=0;i<E[x].size();i++){
        int v=E[x][i];
        if(v!=son[x]) repos(v,v);
    }
}
void update_seg(Node* root,int l,int r ,int ql,int qr ,int v){
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

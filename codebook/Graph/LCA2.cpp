#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
vector<int> tree[MAXN];
int depth[MAXN];
int father[MAXN][20];
void init()
{
    memset(depth, 0, sizeof(depth));
    memset(father, -1, sizeof(father));
}
void dfs(int u)
{
    for (int i = 0; i < tree[u].size(); i++) {
        int v = tree[u][i];
        if (!depth[v]) {
            depth[v] = depth[u] + 1;
            father[v][0] = u;
            dfs(v);
        }
    }
}
void build()
{
    for (int i = 1; (1 << i) < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (father[j][i - 1] != -1) {
                father[j][i] = father[father[j][i - 1]][i - 1];
            }
        }
    }
}
int lca(int u,int v)
{
    if(depth[u]<depth[v]) swap(u,v);
    for(int i =log2(MAXN-1);i>=0;i--)
    {
        if( father[u][i]!=-1 && depth[father[u][i]]>=depth[v]) u=father[u][i];
    }
    if(u==v) return v;
    for(int i=log2(MAXN-1);i>=0;i--)
    {
        if(father[u][i]!=father[v][i])
            u=father[u][i],v=father[v][i];
    }
    return father[u][0];
}

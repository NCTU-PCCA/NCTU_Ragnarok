#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MAXN = 100000 + 100;
struct Edge {
    int to, w;
    Edge(int _to = 0, int _w = 0)
        : to(_to)
        , w(_w)
    {
    }
};
vector<Edge> E[MAXN];
vector<Edge> E2[MAXN];
vector<int> V;
int ds[MAXN];
bool used[MAXN];
int dis[MAXN];
int dis2[110][MAXN];
bool visited[MAXN];
int id[MAXN];
int depth[MAXN];
int father[MAXN][20];
void init(int n)
{
    memset(visited,0,sizeof(visited));
    memset(used, false, sizeof(used));
    memset(dis, 0, sizeof(dis));
    memset(dis2,0,sizeof(dis2));
    memset(id,0,sizeof(id));
    memset(depth, 0, sizeof(depth));
    memset(father, -1, sizeof(father));
    for (int i = 1; i <= n; i++) {
        E[i].clear();
        E2[i].clear();
        ds[i] = i;
    }
    V.clear();
}
void build()
{
    for (int i = 1; i<=19; i++) {
        for (int j = 1; j < MAXN; j++) {
            if (father[j][i - 1] != -1) {
                father[j][i] = father[father[j][i - 1]][i - 1];
            }
        }
    }
}
int lca(int u,int v)
{
    if(depth[u]<depth[v]) swap(u,v);
    for(int i =19;i>=0;i--)
    {
        if( father[u][i]!=-1 && depth[father[u][i]]>=depth[v]) u=father[u][i];
    }
    if(u==v) return v;
    for(int i=19;i>=0;i--)
    {
        if(father[u][i]!=father[v][i])
            u=father[u][i],v=father[v][i];
    }
    return father[u][0];
}
int Find(int x) { return ds[x] == x ? x : (ds[x] = Find(ds[x])); }
void dfs(int u)
{
    for (int i = 0; i < E[u].size(); i++) {
        int v = E[u][i].to;
        if (!visited[v]) {
            visited[v] = true;
            depth[v] = depth[u] + 1;
            father[v][0] = u;
            dis[v] = dis[u] + E[u][i].w;
            dfs(v);
        }
    }
}
void SPFA(int x)
{
    bool vis[MAXN] = {};
    int D[MAXN];
    fill(D, D + MAXN, 2000000000);
    queue<int> q;
    D[x] = 0;
    vis[x] = true;
    q.push(x);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < E2[u].size(); i++) {
            int v = E2[u][i].to;
            int w = E2[u][i].w;
            if (D[u] + w < D[v]) {
                D[v] = D[u] + w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        vis[u] = false;
    }
    for (int i = 0; i < MAXN; i++)
        dis2[id[x]][i] = D[i];
}
int ask(int x,int y){
    int p=lca(x,y);
    int ans=dis[x]+dis[y]-2LL*dis[p];
    for(int i=0 ;i <V.size();i++){
        int v=V[i];
        int idd=id[v];
        ans=min(ans,dis2[idd][x]+dis2[idd][y]);
    }
    return ans;
}
#undef int 
int main()
{
#define int long long 
    int T;
    cin >> T;
    int kase = 1;
    while (T--) {
    int num = 0;
        cout << "Case " << kase++ << ":" << endl;
        int n, m, q;
        cin >> n >> m >> q;
        init(n);
        while (m--) {
            int x, y, w;
            cin >> x >> y >> w;
            E2[x].push_back(Edge(y, w));
            E2[y].push_back(Edge(x, w));
            int fx = Find(x);
            int fy = Find(y);
            if (fx != fy) {
                E[x].push_back(Edge(y, w));
                E[y].push_back(Edge(x, w));
                ds[fx] = fy;
            } else {
                if (!used[x]) {
                    V.push_back(x);
                    used[x] = true;
                    id[x] = num++;
                }
                if (!used[y]) {
                    V.push_back(y);
                    used[y] = true;
                    id[y] = num++;
                }
            }
        }
        visited[1] = true;
        dis[1] = 0;
        depth[1]=1;
        dfs(1);
        build();
        for (int i = 0; i < V.size(); i++) {
            SPFA(V[i]);
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<ask(x,y)<<endl;
        }
    }
    return 0;
}

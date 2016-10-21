/*
 test for LCA Targan
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
//Tarjan
const int MAXN = 10000 + 5; //max_number of nodes
int n;
int root;
int indeg[MAXN]; //入度
vector<int> tree[MAXN];
void inputTree()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        tree[i].clear(), indeg[i] = 0;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        indeg[y]++;
    }
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0) {
            root = i;
            break;
        }
}
vector<int> query[MAXN];
vector<pair<int, int> > Q;
void inputQuery()
{
    for (int i = 1; i <= n; i++) {
        query[i].clear();
    }
    Q.clear();
    int m; //number of query
    //cin >> m;
    m = 1;
    while (m--) {
        int u, v;
        cin >> u >> v;
        query[u].push_back(v);
        query[v].push_back(u);
        Q.push_back(make_pair(u, v));
    }
}
int father[MAXN], depth[MAXN];
void makeSet()
{
    for (int i = 1; i <= n; i++) {
        father[i] = i, depth[i] = 0;
    }
}
int findSet(int x)
{
    return (x == father[x]) ? x : father[x] = findSet(father[x]);
}
void unionSet(int x, int y)
{
    x = findSet(x), y = findSet(y);
    if (x == y)
        return;
    if (depth[x] > depth[y]) {
        father[y] = x;
        depth[x] += depth[y];
        depth[y] = 0;
    } else {
        father[x] = y;
        depth[y] += depth[x];
        depth[x] = 0;
    }
}
int ancestor[MAXN];
//int lca[MAXN][MAXN];
bool visited[MAXN];
void Tarjan(int u)
{
    for (int i = 0; i < tree[u].size(); i++) {
        int v = tree[u][i];
        Tarjan(v);
        unionSet(u, v);
        ancestor[findSet(u)] = u;
    }
    visited[u] = true;
    for (int i = 0; i < query[u].size(); i++) {
        int v = query[u][i];
        if (visited[v]) {
            //lca[u][v] = lca[u][v] = ancestor[findSet(v)];
            cout << ancestor[findSet(v)]<<endl;;
            return;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        inputTree();
        inputQuery();
        makeSet();
        memset(ancestor, 0, sizeof(ancestor));
        memset(visited, 0, sizeof(visited));
        Tarjan(root);
    }

    return 0;
}

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
const int MAXN = 10000 + 5;
vector<int> tree[MAXN];
int depth[MAXN];
int father[MAXN][22];
int root;
void init()
{
    memset(depth, 0, sizeof(depth));
    memset(father, -1, sizeof(father));
}
int n;
void inputTree()
{
    int indeg[MAXN]={};
    cin >> n;
    for (int i = 1; i <= n; i++)
        tree[i].clear(), indeg[i] = 0;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        father[y][0]=x;
        tree[x].push_back(y);
        indeg[y]++;
    }
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0) {
            root = i;
            break;
        }
}
void dfs(int u)
{
    for (int i = 0; i < tree[u].size(); i++) {
        int v = tree[u][i];
        if (!depth[v]) {
            depth[v] = depth[u] + 1;
            dfs(v);
        }
    }
}
void build()
{
    for (int i = 1; i < 22; i++) {
        for (int j = 1; j <= n; j++) {
            if (father[j][i - 1] != -1) {
                father[j][i] = father[father[j][i - 1]][i - 1];
            }
        }
    }
}
int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    for (int i = 21; i >= 0; i--) {
        if ( father[u][i]!= -1 && depth[father[u][i]] >= depth[v])
            u = father[u][i];
    }
    if (u == v)
        return v;
    for (int i = 21; i >= 0; i--) {
        if (father[u][i] != father[v][i])
            u = father[u][i], v = father[v][i];
    }
    return father[u][0];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        init();
        inputTree();
        depth[root]=1;
        dfs(root);
        build();
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
    return 0;
}

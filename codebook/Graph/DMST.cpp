const int MAXN = 1010;
int pre[MAXN], min_dist[MAXN];
struct Edge {
    int from, to, cost;
    Edge() {}
    Edge(int _from, int _to, int _cost)
        : from(_from)
        , to(_to)
        , cost(_cost)
    {
    }
};
vector<Edge> E;
int solve(int n, int m, int root)
{
    int ans = 0;
    while (true) {
        fill(min_dist, min_dist + MAXN, INT_MAX);
        for (int i = 0; i < E.size(); i++) {
            int u = E[i].from, v = E[i].to, cost = E[i].cost;
            if (cost < min_dist[v] && v != u) {
                min_dist[v] = cost;
                pre[v] = u;
            }
        }
        for (int i = 1; i <= n; i++)
            if (min_dist[i] == INT_MAX && i != root)
                return -1;
        int cnt_node = 1, id[MAXN], vis[MAXN];
        memset(id, -1, sizeof(id));
        memset(vis, 0, sizeof(vis));
        min_dist[root] = 0;
        for (int i = 1; i <= n; i++) {
            ans += min_dist[i];
            int v = i;
            while (vis[v] != i && id[v] == -1 && v != root) {
                vis[v] = i;
                v = pre[v];
            }
            if (id[v] == -1 && v != root) {
                for (int u = v; u != v; u = pre[u])
                    id[u] = cnt_node;
                cnt_node++;
            }
        }
        if (cnt_node == 1)
            break;
        for (int i = 1; i <= n; i++)
            if (id[i] == -1)
                id[i] = cntnode++;
        for (int i = 0; i < E.size(); i++) {
            int v = E[i].to;
            E[i].from = id[E[i].from];
            E[i].to = id[E[i].to];
            if (E[i].from ! = E[i].to)
                E[i].cost -= min_dist[v];
        }
        n = cntnode - 1;
        root = id[root];
    }
    return ans;
}

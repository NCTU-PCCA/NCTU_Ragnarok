#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
struct Edge {
    int v; //連的點
    int cap; //容量
    int cost;
    int next; //下一條邊的
} e[N * N];
int id;
int p[N];
int pre[N];
int path[N];
int dist[N]; //dist;
int dp[500][500];

void init() //初始化
{
    memset(e, 0, sizeof(e));
    memset(p, -1, sizeof(p));
    id = 0;
}
void add(int u, int v, int cap, int cost)
{
    e[id].v = v, e[id].cap = cap, e[id].cost = cost, e[id].next = p[u], p[u] = id++;
    e[id].v = u, e[id].cap = 0, e[id].cost = -cost, e[id].next = p[v], p[v] = id++;
}
bool SPFA(int s, int t)
{
    memset(pre, -1, sizeof(pre));
    fill(dist, dist + N, INT_MAX);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (e[i].cap > 0 && dist[u] + e[i].cost < dist[v]) {
                dist[v] = dist[u] + e[i].cost;
                pre[v] = u; //路徑
                path[v] = i; //邊的編號
                q.push(v);
            }
        }
    }
    if (pre[t] == -1)
        return false;
    return true;
}
int MinCostFlow(int s, int t)
{
    int cost = 0;
    int flow = 0;
    while (SPFA(s, t)) {
        int f = INT_MAX;
        for (int u = t; u != s; u = pre[u])
            f = min(f, e[path[u]].cap);
        flow += f;
        cost += dist[t] * f;
        for (int u = t; u != s; u = pre[u]) {
            e[path[u]].cap -= f;
            e[path[u] ^ 1].cap += f;
        }
    }
    return cost; //cost
}
int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = (i == j) ? 0 : 1e8;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            dp[x][y] = 1;
            dp[y][x] = 1;
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
        vector<int> v1;
        vector<int> v2;
        int S = 1001;
        int T = 1002;
        init();
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 1) {
                add(S, i, 1, 0);
                v1.push_back(i);
            }
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 1) {
                v2.push_back(i);
                add(i+500, T, 1, 0);
            }
        }
        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                add(v1[i], v2[j]+500, 1, dp[v1[i]][v2[j]]);
            }
        }
        cout << MinCostFlow(S, T) << endl;
        ;
    }

    return 0;
}

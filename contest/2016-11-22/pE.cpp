nclude<bits / stdc++.h> using namespace std;
struct Node {
    int point; //點
    int dis; // 距離源點的距離
    Node(int _point = 0, int _dis = 0)
    {
        point = _point, dis = _dis;
    }
    bool operator<(const Node& e) const
    {
        return dis > e.dis; // for the priority queue 定義小於 且顛倒 讓priority queue 由 小到大
    }
};
struct Edge {
    int v;
    int cost;
    Edge(int _v = 0, int _cost = 0)
    {
        v = _v, cost = _cost;
    }
};
int p[20000 + 10];
int dis[20][20000 + 10];
vector<Edge> e[20000 + 10];
void Dijkstra(int s, int num) // 起點
{
    fill(&dis[num][0], &dis[num][20000 + 10], INT_MAX);
    priority_queue<Node> pq;
    pq.push(Node(s, 0));
    dis[num][s] = 0;
    while (!pq.empty()) {
        Node top = pq.top();
        pq.pop();
        int u = top.point;
        int val = top.dis;
        if (val != dis[num][u])
            continue;
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i].v;
            int cost = e[u][i].cost;
            if (dis[num][u] + cost < dis[num][v]) {
                dis[num][v] = dis[num][u] + cost;
                pq.push(Node(v, dis[num][v]));
            }
        }
    }
}
int n, m;
int fee, company, K;
int D[1 << 16];
int DD[1 << 16];
int dp[1 << 16];
int d1(int a, int b, int c, int d)
{
    int aa = p[a], bb = p[b], cc = p[c], dd = p[d];
    return fee + dis[K][aa] + dis[a][bb] + dis[b][cc] + dis[c][dd];
}
int d2(int a, int b, int c)
{
    int aa = p[a], bb = p[b], cc = p[c];
    return fee + dis[K][aa] + dis[a][bb] + dis[b][cc];
}
int d3(int a, int b)
{
    int aa = p[a], bb = p[b];
    return fee + dis[K][aa] + dis[a][bb];
}
int main()
{
    scanf("%d%d", &n, &m);
    while (m--) {
        int t, u, v, c;
        scanf("%d%d%d%d", &t, &u, &v, &c);
        e[u].push_back(Edge(v, c));
        if (t == 2)
            e[v].push_back(Edge(u, c));
    }
    scanf("%d%d%d", &fee, &company, &K);
    for (int i = 0; i < K; i++)
        scanf("%d", p + i);
    for (int i = 0; i < K; i++)
        Dijkstra(p[i], i);
    Dijkstra(company, K);
    fill(D, D + (1 << 16), INT_MAX);
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            for (int k = 0; k < K; k++)
                for (int l = 0; l < K; l++) {
                    if (i == k || i == j || i == l || j == k || j == l || k == l)
                        continue;
                    int tmp = 0;
                    tmp += 1 << i;
                    tmp += 1 << j;
                    tmp += 1 << k;
                    tmp += 1 << l;
                    D[tmp] = min(D[tmp], d1(i, j, k, l));
                }
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            for (int k = 0; k < K; k++) {
                if (i == k || i == j || j == k)
                    continue;
                int tmp = 0;
                tmp += 1 << i;
                tmp += 1 << j;
                tmp += 1 << k;
                D[tmp] = min(D[tmp], d2(i, j, k));
            }
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++) {
            if (i == j)
                continue;
            int tmp = 0;
            tmp += 1 << i;
            tmp += 1 << j;
            D[tmp] = min(D[tmp], d3(i, j));
        }
    for (int i = 0; i < K; i++) {
        D[1 << i] = min(D[1 << i], fee + dis[K][p[i]]);
    }
    int idx = 0;
    for (int i = 0; i < (1 << K); i++) {
        if (D[i] != INT_MAX) {
            DD[idx++] = i;
        }
    }
    fill(dp, dp + (1 << 16), INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < (1 << K); i++) {
        for (int j = 0; j < idx; j++) {
            int mask = DD[j];
            if (i & mask)
                continue;
            dp[i | mask] = min(dp[i | mask], dp[i] + D[mask]);
        }
    }
    printf("%d\n", dp[(1 << K) - 1]);

    return 0;
}

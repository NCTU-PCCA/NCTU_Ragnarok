#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
struct Edge {
    int v;
    int cap;
    int cost;
    int next;
} e[N * N];
struct Node {
    int to;
    int dis;
    Node() {}
    Node(int _to, int _dis)
        : to(_to)
        , dis(_dis)
    {
    }
    bool operator<(const Node& v) const
    {
        return dis > v.dis;
    }
};
int n;
int id, p[N + 100], pre[N + 100], path[N + 100], dist[N + 100];
void init()
{
    memset(p, -1, sizeof(p));
    id = 0;
}
void add(int u, int v, int cap, int cost)
{
    e[id].v = v, e[id].cap = cap, e[id].cost = cost, e[id].next = p[u];
    p[u] = id++;
    e[id].v = u, e[id].cap = 0, e[id].cost = -cost, e[id].next = p[v];
    p[v] = id++;
}
void PRE(vector<int>& seed)
{
    for (int i = 0; i <= (n + 2); i++)
        pre[i] = -1;
    for (int i = 0; i <= (n + 2); i++)
        dist[i] = INT_MAX;
    priority_queue<Node> q;
    for (int i = 0; i < seed.size(); i++) {
        dist[seed[i]] = 0;
        q.push(Node(seed[i], 0));
    }
    while (!q.empty()) {
        auto pp = q.top();
        int u = pp.to;
        q.pop();
        if (pp.dis != dist[u])
            continue;
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (e[i].cap > 0 && dist[u] + e[i].cost < dist[v]) {
                dist[v] = dist[u] + e[i].cost;
                pre[v] = u;
                path[v] = i;
                q.push(Node(v, dist[v]));
            }
        }
    }
}
/*
bool SPFA(int s, int t)
{
    memset(pre, -1, sizeof(pre));
    for(int i=0;i<=(n+2);i++) pre[i]=-1;
    for(int i=0;i<=(n+2);i++) dist[i]=INT_MAX;
    dist[s] = 0;
    q.push(Node(s, 0));
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
        for (int u = t; u != s; u = pre[u]) {
            f = min(f, e[path[u]].cap);
        }
        flow += f;
        cost += dist[t] * f;
        for (int u = t; u != s; u = pre[u]) {
            e[path[u]].cap -= f;
            e[path[u] ^ 1].cap += f;
        }
    }
    return cost;
}
*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n) {
        int S = n + 1;
        int T = n + 2;
        cin.ignore();
        string in;
        init();
        while (getline(cin, in)) {
            if (in.size() == 0)
                break;
            stringstream ss(in);
            int u, v, cost;
            ss >> u >> v >> cost;
            add(u, v, INT_MAX, cost);
        }
        getline(cin, in);
        stringstream ss(in);
        int aud;
        vector<int> aud_ids;
        while (ss >> aud) {
            add(aud, T, 1, 0);
            aud_ids.push_back(aud);
        }
        int num_r;
        cin >> num_r;
        vector<int> seed_ids, seed_edge_ids;
        while (num_r--) {
            for (int i = 0; i < seed_edge_ids.size(); i++) {
                int eid = seed_edge_ids[i];
                e[eid].cap = 0;
                e[eid ^ 1].cap = 0;
            }
            seed_edge_ids.clear();
            seed_ids.clear();
            int num;
            cin >> num;
            while (num--) {
                int s;
                cin >> s;
                add(S, s, 1, 0);
                seed_ids.push_back(s);
                seed_edge_ids.push_back(id);
            }
            PRE(seed_ids);
            int ans = 0;
            for (int i = 0; i < aud_ids.size(); i++) {
                int localans = INT_MAX;
                for (int k = 0; k < seed_ids.size(); k++) {
                    localans = min(localans, dist[aud_ids[i]] - dist[seed_ids[k]]);
                }
                ans = max(ans, localans);
            }
            cout << ans << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const double EPS =1e-6;
int fcmp(double x){
    if(fabs(x)<EPS) return 0;
    return (x>0)?1:-1;
}
const int N = 10000;
struct Edge {
    int v, cap, next;
    double cost;
} e[N * N];
int id;
int p[N];
int pre[N];
int path[N];
double dist[N];
struct Point {
    double x, y, h;
    Point() {}
    Point(double _x, double _y, double _h)
    {
        x = _x;
        y = _y;
        h = _h;
    }
};
double len(Point a, Point b){
    double dx=a.x-b.x;
    double dy=a.y-b.y;
    double dh=a.h-b.h;
    double ans=dx*dx+dy*dy+dh*dh;
    return sqrt(ans);
}
void init()
{
    memset(e, 0, sizeof(e));
    memset(p, -1, sizeof(p));
    id = 0;
}
void add(int u, int v, int cap, double cost)
{
    e[id].v = v;
    e[id].cap = cap, e[id].cost = cost, e[id].next = p[u], p[u] = id++;
    e[id].v = u;
    e[id].cap = 0, e[id].cost = cost, e[id].next = p[v], p[v] = id++;
}
bool SPFA(int s, int t)
{
    memset(pre, -1, sizeof(pre));
    fill(dist, dist + N, INT_MAX);
    bool vis[N] = {};
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (e[i].cap > 0 && dist[u] + e[i].cost < dist[v]) {
                dist[v] = dist[u] + e[i].cost;
                pre[v] = u;
                path[v] = i;
                if (!vis[v])
                    vis[v] = true, q.push(v);
            }
        }
    }
    if (pre[t] == -1)
        return false;
    return true;
}
double MinCostFlow(int s, int t)
{
    double cost = 0;
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
    return cost;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s, t, q;
    cin >> n >> s >> t >> q;
    vector<Point> v;
    for(int i=0;i<n;i++){
        double x,y,h;cin>>x>>y>>h;
        v.push_back(Point(x,y,h));
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double ans =len(v[i],v[j]);
            if(fcmp(q-ans)>=0){


            }
        }
    }

    return 0;
}

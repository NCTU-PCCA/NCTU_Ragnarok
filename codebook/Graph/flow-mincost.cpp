#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
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
    bool vis[N]={};
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u]=false;
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (e[i].cap > 0 && dist[u] + e[i].cost < dist[v]) {
                dist[v] = dist[u] + e[i].cost;
                pre[v] = u; //路徑
                path[v] = i; //邊的編號
                if(!vis[v])
                vis[v]=true,q.push(v);
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
        flow+=f;
        cost+=dist[t]*f;
        for(int u=t;u!=s;u=pre[u]){
            e[path[u]].cap-=f;
            e[path[u]^1].cap+=f;
        }
    }
    return cost; //cost
}

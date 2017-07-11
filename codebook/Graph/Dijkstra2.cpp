#include <queue>
#include <vector>
using namespace std;
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
int dis[10000];
vector<Edge> e[10000];
void init(int n) // initialize
{
    for (int i = 0; i < n; i++) {
        dis[i] = 1e9;
        e[i].clear();
    }
}
void Dijkstra(int s) // 起點
{

    priority_queue<Node> pq;
    pq.push(Node(s, 0));
    dis[s] = 0;
    while (!pq.empty()) {
        Node top = pq.top();
        pq.pop();
        int u = top.point;
        int val = top.dis;
        if (val != dis[u])
            continue; // 加速
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i].v;
            int cost = e[u][i].cost;
            if (dis[u] + cost < dis[v]) {
                dis[v] = dis[u] + cost;
                pq.push(Node(v, dis[v]));
            }
        }
    }
}

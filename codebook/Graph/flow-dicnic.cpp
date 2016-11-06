#include <bits/stdc++.h>
using namespace std;
int id; // zero-based
int p[10000]; // 每個點連到的最後一條邊的編號
int work[10000];
int S, T; // S:源點 T:匯點
int n; // 點數
vector<string> ans;
map<string, int> idx;
struct Edge {
    int v; //連的點
    int cap; //容量
    int next; //下一條邊的
} e[1000 * 1000];
int dis[10000];
void init() //初始化
{
    memset(e, 0, sizeof(e));
    memset(p, -1, sizeof(p));
    id = 0;
}
void add(int u, int v, int c)
{
    e[id].v = v, e[id].cap = c, e[id].next = p[u], p[u] = id++;
    e[id].v = u, e[id].cap = 0, e[id].next = p[v], p[v] = id++;
}
bool BFS(int s, int t) //利用BFS建立分層圖
{
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int i = p[top]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (dis[v] == -1 && e[i].cap) {
                dis[v] = dis[top] + 1;
                q.push(v);
            }
        }
    }
    return dis[t] >= 0;
}
int DFS(int x, int low)
{
    if (x == T)
        return low;
    for (int &i = work[x]; i != -1; i = e[i].next) { //從上次的開始
        int v = e[i].v;
        if (dis[v] > 0 && dis[v] == dis[x] + 1 && e[i].cap) //只能從深度為x連到x+1 &&還有空間
        {
            int a = DFS(v, min(low, e[i].cap)); //找到這條路徑中剩餘空間最小的邊
            if (a > 0) {
                e[i].cap -= a;
                e[i ^ 1].cap += a; // 利用 0-based xor 的性質 0^1=1 1^1=0;
                return a;
            }
        }
    }
    return 0;
}
int dicnic()
{
    int flow = 0;
    while (BFS(S, T)) { //持續建立分層圖
        int mind;
        for(int i=0;i<=T;i++) work[i]=p[i];
        while ((mind = DFS(S, INT_MAX)))
            flow += mind; //持續擴充
    }
    return flow;
}

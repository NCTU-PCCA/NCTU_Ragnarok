#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int id; // zero-based
int p[3000]; // 每個點連到的最後一條邊的編號
int work[3000];
struct Edge {
    int v; 
    int cap; 
    int next;
} e[10000 * 1000];
int dis[10000];
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
    return (dis[t] >= 0);
}
int DFS(int x, int low, int T)
{
    if (x == T)
        return low;
    for (int & i = work[x] ; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (e[i].cap > 0 && dis[v] == dis[x] + 1) {
            int a = DFS(v, min(low, e[i].cap), T);
            if (a > 0) {
                e[i].cap -= a;
                e[i ^ 1].cap += a;
                return a;
            }
        }
    }
    return 0;
}
int dicnic(int S, int T)
{
    int flow = 0;
    while (BFS(S, T)) { //持續建立分層
        int mind;
		for(int i=0;i<=T;i++) work[i]=p[i];
        while ((mind = DFS(S, INT_MAX, T)))
            flow += mind; //持續擴充
    }
    return flow;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s, r, f, t;
    cin >> s >> r >> f >> t;
    int S = 0;
    int T = s + t + t + 1;
    unordered_map<string, int> idx;
    memset(e, 0, sizeof(e));
    memset(p, -1, sizeof(p));
    id = 0;
    int num = 0;
    for (int i = 0; i < r; i++) {
        string a;
        cin >> a;
        if (!idx.count(a)) {
            num++;
            idx[a] = num;
        }
        int idd = idx[a];
        add(S, idd, 1);
    }
    for (int i = 0; i < f; i++) {
        string a;
        cin >> a;
        if (!idx.count(a)) {
            num++;
            idx[a] = num;
        }
        int idd = idx[a];
        add(idd, T, 1);
    }
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        add(i + s, i + s + t, 1);
        while (n--) {
            string a;
            cin >> a;
            if (idx.find(a) == idx.end()) {
                num++;
                idx[a] = num;
            }
            int idd = idx[a];
            add(idd, i + s, 1);
            add(i + s + t, idd, 1);
        }
    }
    cout << dicnic(S, T) << endl;

    return 0;
}

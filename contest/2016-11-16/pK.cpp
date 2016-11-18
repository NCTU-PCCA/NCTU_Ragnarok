#include <bits/stdc++.h>
using namespace std;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int id; // zero-based
int p[10000]; // 每個點連到的最後一條邊的編號
int work[10000];
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
int DFS(int x, int low, int T)
{
    if (x == T)
        return low;
    for (int& i = work[x]; i != -1; i = e[i].next) { //從上次的開始
        int v = e[i].v;
        if (dis[v] > 0 && dis[v] == dis[x] + 1 && e[i].cap) //只能從深度為x連到x+1 &&還有空間
        {
            int a = DFS(v, min(low, e[i].cap), T); //找到這條路徑中剩餘空間最小的邊
            if (a > 0) {
                e[i].cap -= a;
                e[i ^ 1].cap += a; // 利用 0-based xor 的性質 0^1=1 1^1=0;
                return a;
            }
        }
    }
    return 0;
}
int dicnic(int S, int T)
{
    int flow = 0;
    while (BFS(S, T)) { //持續建立分層圖
        int mind;
        for (int i = 0; i <= T; i++)
            work[i] = p[i];
        while ((mind = DFS(S, INT_MAX, T)))
            flow += mind; //持續擴充
    }
    return flow;
}
int main()
{
    string in;
    int m = 0;
    int n = 0;
    vector<string> G;
    init();
    int S, T;
    while (getline(cin, in)) {
        if (in.size() == 0) {
            S = 1810;
            T = 1811;
            init();
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int in = i * n + j;
                    int out = in + 900;
                    add(in, out, 1);
                    char c = G[i][j];
                    if (c == 'W')
                        add(S, in, 1);
                    else if (c == 'N')
                        add(out, T, 1);
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= m || x < 0 || y >= n || y < 0)
                            continue;
                        int in2 = x * n + y;
                        char c2 = G[x][y];
                        if (c == 'W' && c2 == 'I')
                            add(out, in2, 1);
                        else if (c == 'I' && c2 == 'N')
                            add(out, in2, 1);
                    }
                }
            }
            cout << dicnic(S, T) << endl;
            m = 0;
            n = 0;
            G.clear();
            continue;
        }
        m++;
        n = in.size();
        G.push_back(in);
    }
    S = 1810;
    T = 1811;
    init();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int in = i * n + j;
            int out = in + 900;
            add(in, out, 1);
            char c = G[i][j];
            if (c == 'W')
                add(S, in, 1);
            else if (c == 'N')
                add(out, T, 1);
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= m || x < 0 || y >= n || y < 0)
                    continue;
                int in2 = x * n + y;
                char c2 = G[x][y];
                if (c == 'W' && c2 == 'I')
                    add(out, in2, 1);
                else if (c == 'I' && c2 == 'N')
                    add(out, in2, 1);
            }
        }
    }
    cout << dicnic(S, T) << endl;

    return 0;
}

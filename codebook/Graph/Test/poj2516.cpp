#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 210;
const int INF = 0x3f3f3f3f;
int pre[MAXN];
int path[MAXN];
int dist[MAXN]; //dist;
int cost[MAXN][MAXN];
int cap[MAXN][MAXN];
bool SPFA(int s, int t)
{
    memset(pre, -1, sizeof(pre));
    fill(dist, dist + MAXN, INF);
    bool vis[MAXN] = {};
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        //cerr<<u<<endl;
        q.pop();
        vis[u] = false;
        for (int v = s; v <= t; v++) {
            if (cap[u][v] > 0 && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                pre[v] = u; //路徑
                if (!vis[v])
                    vis[v] = true, q.push(v);
            }
        }
    }
    if (dist[t]>=INF)
        return false;
    return true;
}
pair<int, int> MinCostFlow(int s, int t)
{
    int cost = 0;
    int flow = 0;
    while (SPFA(s, t)) {
        int f = INF;
        for (int u = t; u != s; u = pre[u])
            f = min(f, cap[pre[u]][u]);
        flow += f;
        cost += dist[t] * f;
        for (int u = t; u != s; u = pre[u]) {
            cap[pre[u]][u] -= f;
            cap[u][pre[u]] += f;
        }
    }
    return make_pair(flow, cost); //cost
}

int main()
{
    int N, M, K;
    while (scanf("%d%d%d", &N, &M, &K) && (N || M || K)) {
        int shop[200][200];
        int supply[200][200];
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= K; j++)
                scanf("%d", &shop[i][j]);
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= K; j++)
                scanf("%d", &supply[i][j]);
        bool flag = false;
        int ans = 0;
        for (int k = 1; k <= K; k++) {
            memset(cost, 0, sizeof(cost));
            memset(cap, 0, sizeof(cap));
            for (int i = 1; i <= M; i++) {
                for (int j = M + 1; j <= N + M; j++)
                    cap[i][j] = INF;
            }
            int sum = 0;
            int S = 0;
            int T = N + M + 1;
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= M; j++) {
                    int x;
                    scanf("%d", &x);
                    cost[j][i + M] = x;
                    cost[i + M][j] = -x;
                }
            if(flag) continue;
            for (int i = 1; i <= M; i++)
                cap[S][i] = supply[i][k];
            for (int i = 1; i <= N; i++)
                sum += shop[i][k], cap[i + M][T] = shop[i][k];
            pair<int, int> Ans = MinCostFlow(S, T);
            if (Ans.first < sum)
                flag = true;
            ans += Ans.second;
        }
        printf("%d\n", (flag ? -1 : ans));
    }

    return 0;
}

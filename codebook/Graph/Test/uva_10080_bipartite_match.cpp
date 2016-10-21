#define op_io                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
vector<int> g[10000]; //鄰接表
bool check[10000];
int match[10000];
int num_left, num_right;
void init(int n)
{
    num_left = num_right = 0;
    for (int i = 0; i < n; i++)
        g[i].clear();
}
bool DFS(int u)
{
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!check[v]) {
            check[v] = true;
            if (match[v] == -1 || DFS(match[v])) // ||短路運算
            {
                match[v] = u;
                match[u] = v;
                return true; // 一找到未匹配點就連接
            }
        }
    }
    return false;
}
int Hungarian_DFS() //匈牙利算法
{
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < num_left; i++) //只要對二分圖的一邊即可
    {
        memset(check, 0, sizeof(check));
        if (DFS(i))
            ans++;
    }
    return ans;
}
int Hungarian_BFS()
{
    int prev[10000]; //儲存路徑
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < num_left; i++) {
        memset(check, 0, sizeof(check));
        if (match[i] == -1) {
            queue<int> q;
            q.push(i);
            prev[i] = -1;
            bool flag = false;
            while (!q.empty() && !flag) {
                int u = q.front();
                q.pop();
                for (int j = 0; j < g[u].size() && !flag; j++) {
                    int v = g[u][j];
                    if (!check[v]) {
                        check[v] = true;
                        if (match[v] != -1) {
                            q.push(match[v]);
                            prev[match[v]] = u;

                        } else {
                            flag = true;
                            int d = u, e = v;
                            while (d != -1) {
                                int t = match[d];
                                match[d] = e;
                                match[e] = d;
                                d = prev[d];
                                e = t;
                            }
                        }
                    }
                }
            }
            if (match[i] != -1)
                ans++;
        }
    }
    return ans;
}
struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0)
        : x(_x)
        , y(_y)
    {
    }
};
bool correct(Point x, Point y, int s, int v)
{
    double length = sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
    if (length > s * v)
        return false;
    return true;
}
int main()
{
    op_io;
    int n, m, s, v;
    int index = 0;
    while (cin >> n >> m >> s >> v) {
        init(n + m);
        num_left = n;
        num_right = m;
        vector<Point> p;
        for (int i = 0; i < n + m; i++) {
            double x, y;
            cin >> x >> y;
            p.push_back(Point(x, y));
        }
        for (int i = 0; i < n; i++) {
            for (int j = n; j < n + m; j++) {
                if (correct(p[i], p[j], s, v)) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int ans = Hungarian_BFS();
        cout << n - ans << endl;
    }

    return 0;
}

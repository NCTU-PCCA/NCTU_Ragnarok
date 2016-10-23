#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
struct Point {
    int x, y, id;
    Point(int _x, int _y, int _id)
        : x(_x)
        , y(_y)
        , id(_id)
    {
    }
    bool operator<(const Point& p) const
    {
        return (x != p.x) ? x < p.x : y < p.y;
    }
};

struct BIT {
    int min_val, pos;
    void init()
    {
        min_val = INT_MAX;
        pos = -1;
    }
} bit[N];
struct Edge {
    int u, v, d;
    Edge() {}
    Edge(int _u, int _v, int _d)
        : u(_u)
        , v(_v)
        , d(_d)
    {
    }
    bool operator<(const Edge& e) const
    {
        return d < e.d;
    }
};
vector<Point> p;
vector<Edge> E;
int ds[N]; //disjoint set for kruskal

void add_edge(int u, int v, int d)
{
    E.push_back(Edge(u, v, d));
}
int find(int x)
{
    return ds[x] = (x == ds[x] ? x : find(ds[x]));
}
int dist(int i, int j)
{
    return abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y);
}
inline int lowbit(int x)
{
    return x & (-x);
}
void update(int x, int val, int pos)
{
    for (int i = x; i >= 1; i -= lowbit(i)) {
        if (val < bit[i].min_val)
            bit[i].min_val = val, bit[i].pos = pos;
    }
}
int query(int x, int m)
{
    int min_val = INT_MAX, pos = -1;
    for (int i = x; i <= m; i += lowbit(i)) {
        if (bit[i].min_val < min_val) {
            min_val = bit[i].min_val, pos = bit[i].pos;
        }
    }
    return pos;
}
int Manhattan_MST(vector<Point>& P)
{
    int n = P.size();
    for (int dir = 0; dir < 4; dir++) {
        if (dir == 1 || dir == 3) {
            for (int i = 0; i < n; i++)
                swap(P[i].x, P[i].y);
        } else if (dir == 2) {
            for (int i = 0; i < n; i++)
                P[i].x = -P[i].x;
        }

        int T[N], hs[N];
        sort(P.begin(), P.end());
        for (int i = 0; i < n; i++) { //discretize
            T[i] = hs[i] = p[i].y - p[i].x;
        }
        sort(hs, hs + n);
        int m = unique(hs, hs + n) - hs;
        for (int i = 1; i <= m; i++)
            bit[i].init();
        for (int i = n - 1; i >= 0; i--) {
            int pos = lower_bound(hs, hs + m, T[i]) - hs + 1; //Bit is 1-based
            int w = query(pos, m);
            if (w != -1)
                add_edge(p[i].id, p[w].id, dist(i, w));
            update(pos, p[i].x + p[i].y, i);
        }
    }
    sort(E.begin(), E.end());
    int ans = 0;
    int p = 1;
    for (int i = 0; i < n; i++)
        ds[i] = i;
    for (int i = 0; i < (int)E.size() && p <= n; i++) {
        int fa = find(E[i].u);
        int fb = find(E[i].v);
        if (fa != fb) {
            p++;
            ds[fa] = fb;
            ans += E[i].d;
        }
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        p.clear();
        E.clear();
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            p.push_back(Point(x, y, i));
        }
        cout << Manhattan_MST(p) * 2 << endl;
    }

    return 0;
}

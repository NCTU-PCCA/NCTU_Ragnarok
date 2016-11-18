#include <bits/stdc++.h>
using namespace std;
int ds[30000 + 1];
void init(int n)
{
    for (int i = 1; i <= n; i++)
        ds[i] = i;
}
int Find(int x)
{
    return ds[x] == x ? x : (ds[x] = Find(ds[x]));
}
int con;
void Union(int x, int y)
{
    x = Find(x), y = Find(y);
    if (x != y) {
        con--;
        ds[x] = y;
    }
}
struct Edge {
    int r, c, cost;
    Edge() {}
    Edge(int _r, int _c, int _cost)
        : r(_r)
        , c(_c)
        , cost(_cost)
    {
    }
    bool operator<(const Edge& e) const
    {
        return cost < e.cost;
    }
};
int main()
{
    int T;
    cin >> T;
    int kase=1;
    while (T--) {
    char g[105][105] = {};
        int R, C;
        cin >> R >> C;
        init(30000);
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                cin >> g[i][j];
            }
        }
        con = R * C * 2;
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                int left = 2 * (i * C + j) + 1;
                int right = 2 * (i * C + j) + 2;
                if (g[i][j] == '\\') {
                    int left2 = 2 * ((i + 1) * C + j) + 1;
                    int right2 = 2 * ((i + 1) * C + j) + 2;
                    if (g[i + 1][j] == '/') {
                        Union(left, left2);

                    } else if (g[i + 1][j] == '\\') {
                        Union(left, right2);
                    }
                    left2 = 2 * (i * C + j + 1) + 1;
                    right2 = 2 * (i * C + j + 1) + 2;
                    if (g[i][j + 1] == '\\') {
                        Union(right, left2);
                    } else if (g[i][j + 1] == '/') {
                        Union(right, left2);
                    }

                } else if (g[i][j] == '/') {
                    int left2 = 2 * ((i + 1) * C + j) + 1;
                    int right2 = 2 * ((i + 1) * C + j) + 2;
                    if (g[i + 1][j] == '/') {
                        Union(right, left2);

                    } else if (g[i + 1][j] == '\\') {
                        Union(right, right2);
                    }
                    left2 = 2 * (i * C + j + 1) + 1;
                    right2 = 2 * (i * C + j + 1) + 2;
                    if (g[i][j + 1] == '\\') {
                        Union(right, left2);
                    } else if (g[i][j + 1] == '/') {
                        Union(right, left2);
                    }
                }
            }
        }
        vector<Edge> v;
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                int c;
                cin >> c;
                v.push_back(Edge(i, j, c));
            }
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < v.size() && con > 1; i++) {
            int con2=con;
            int r = v[i].r;
            int c = v[i].c;
            int cost = v[i].cost;
            int left = 2 * (r * C + c) + 1;
            int right = 2 * (r * C + c) + 2;
            if (g[r][c] == '\\') {
                Union(left,right);

            } else if (g[r][c] == '/') {
                Union(left,right);
            }
            if(con2>con) ans+=cost;

        }
        cout<<"Case "<<kase++<<": ";
        cout<<ans<<endl;
    }

    return 0;
}

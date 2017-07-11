// a0919610611/fuyu0425/twleo
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define int long long
const int N = 20005;
struct Edge {
    int u, v, cost;
    Edge(int _u = 0, int _v = 0, int _cost = 0)
    {
        u = _u, v = _v, cost = _cost;
    }
    bool operator<(const Edge& a) const
    {
        return cost < a.cost;
    }
};
vector<Edge> E;
int ds[N];
void Init(int n)
{
    E.clear();
    for (int i = 0; i < n; i++)
        ds[i] = i;
}
int Find(int x)
{
    return (ds[x] == x) ? x : (ds[x] = Find(ds[x]));
}
int kruskal(int n)
{
    sort(E.begin(), E.end());
    int ans = 0;
    int num = 1;
    for (int i = 0; i < E.size(); i++) {
        Edge e = E[i];
        int u = e.u, v = e.v;
        u = Find(u);
        v = Find(v);
        if (u != v) {
            ds[u] = v;
            num++;
            ans += e.cost;
        }
        if (num == n)
            break;
    }
    return ans;
}
#undef int
int main()
{
#define int long long
    int N;
    while (cin >> N) {
        Init(N);
        int d[100][100];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> d[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                E.push_back(Edge(i, j, d[i][j]));
            }
        }
        cout << kruskal(N) << endl;
    }

    return 0;
}

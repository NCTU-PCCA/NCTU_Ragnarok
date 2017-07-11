#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

pair<int, int> node[1010];
int s[1010];

int dist(int na, int nb)
{
    pair<int, int> a = node[na], b = node[nb];
    return ((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void init(int n)
{
    for (int i = 1; i <= n; i++)
        s[i] = i;
}
int Find(int x) { return x == s[x] ? x : s[x] = Find(s[x]); }
void Union(int x, int y)
{
    if (s[x] == 0 || s[y] == 0)
        return;
    s[Find(x)] = Find(y);
}

int main()
{
    int N, D;
    cin >> N >> D;
    for (int i = 1; i <= N; ++i) {
        int x, y;
        cin >> x >> y;
        node[i].first = x;
        node[i].second = y;
    }
    getchar();
    char c;
    while (cin >> c) {
        if (c == 'O') {
            int point;
            cin >> point;
            s[point] = point;
            for (int i = 1; i <= N; ++i) {
                if (i == point)
                    continue;
                if (dist(point, i) <= D * D) {
                    Union(point, i);
                    //for(int k = 1; k <= N; ++k) cout << s[k] << ' ';cout << endl;
                    //
                }
            }

        } else {
            int a, b;
            cin >> a >> b;
            if (Find(a) == Find(b))
                cout << "SUCCESS" << endl;
            else
                cout << "FAIL" << endl;
        }
    }
    return 0;
}

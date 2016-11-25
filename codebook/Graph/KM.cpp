#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int n;
int g[MAXN][MAXN], lx[MAXN], ly[MAXN];
int match[MAXN], slack[MAXN];
bool vsx[MAXN], vsy[MAXN];

bool find(int x)
{
    vsx[x] = 1;
    for (int i = 0; i < n; i++) {
        if (vsy[i])
            continue;
        int t = lx[x] + ly[i] - g[x][i];
        if (!t) {
            vsy[i] = 1;
            if (match[i] == -1 || find(match[i])) {
                match[x] = i;
                return true;
            }
        } else
            slack[i] = min(slack[i], t);
    }
    return 0;
}
int km(bool MIN = false) //二分圖最大匹配
{
    if (MIN)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = -g[i][j];
    fill(lx, lx + n, INT_MAX);
    fill(ly, ly + n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            lx[i] = min(lx[i], g[i][j]);
    memset(match, -1, sizeof(match));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            fill(slack, slack + n, INT_MAX);
        while (true) {
            memset(vsx, 0, sizeof(vsx));
            memset(vsy, 0, sizeof(vsy));
            if (find(i))
                break;
            int d = INT_MAX;
            for (int j = 0; j < n; j++)
                if (!vsy[j])
                    d = min(d, slack[j]);
            for (int j = 0; j < n; j++) {
                if (vsx[j])
                    lx[j] -= d;
                if (vsy[j])
                    ly[j] += d;
                else
                    slack[j] -= d;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += g[match[i]][i];
    if (MIN) {
        sum = -sum;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = -g[i][j];
    }
    return sum;
}

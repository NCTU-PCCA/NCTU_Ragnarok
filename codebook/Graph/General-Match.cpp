#include <bits/stdc++.h>
using namespace std;
struct DisjointSet {
    int N;
    vector<int> p;
    DisjointSet(int n)
        : N(n)
        , p(vector<int>(N))
    {
        init();
    }
    void init()
    {
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int find(int x)
    {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void U(int a, int b)
    {
        p[find(b)] = find(a);
    }
};
struct GMatch {
    int N;
    vector<vector<int> > vc;
    DisjointSet djs;
    vector<int> m, d, c1, c2, p, vis;
    queue<int> q;
    int ts;
    GMatch(int n)
        : N(n)
        , vc(vector<vector<int> >(N + 1))
        , djs(DisjointSet(N))
        , ts(0)
    {
    }
    void add(int a, int b)
    {
        vc[a].push_back(b);
        vc[b].push_back(a);
    }
    void path(int x, int r)
    {
        if (x == r)
            return;
        if (d[x] == 0) {
            int i = p[x], j = p[p[x]];
            path(j, r);
            m[i] = j, m[j] = i;

        } else if (d[x] == 1) {
            int i = c1[x], j = c2[x];
            path(i, m[x]);
            path(j, r);
            m[i] = j, m[j] = i;
        }
    }
    void blossom(int x, int y, int bi)
    {
        for (int i = djs.find(x); i != bi; i = djs.find(p[i])) {
            djs.U(bi, i);
            if (d[i] == 1)
                c1[i] = x, c2[i] = y, q.push(i);
        }
    }
    int lca(int x, int y, int r)
    {
        ts++;
        vis[r] = ts;
        for (int i = djs.find(x); i != r; i = djs.find(p[i]))
            vis[i] = ts;
        int b;
        for (b = djs.find(y); vis[b] != ts; b = djs.find(p[b]))
            ;
        return b;
    }
    bool Match(int x)
    {
        djs.init();
        d = vector<int>(N + 1, -1);
        d[x] = 0;
        q = queue<int>();
        q.push(x);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : vc[u]) {
                if (m[v] != v && djs.find(u) != djs.find(v)) {
                    if (d[v] == -1) {
                        if (m[v] == -1) {
                            path(u, x);
                            m[u] = v, m[v] = u;
                            return true;

                        } else {
                            p[v] = u, p[m[v]] = v;
                            d[v] = 1, d[m[v]] = 0;
                            q.push(m[v]);
                        }

                    } else {
                        if (d[djs.find(v)] == 0) {
                            int bi = lca(u, v, x);
                            blossom(u, v, bi);
                            blossom(v, u, bi);
                        }
                    }
                }
            }
        }
        return false;
    }
    int Solve()
    {
        m = c1 = c2 = d = p = vis = vector<int>(N + 1, -1);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (m[i] == -1) {
                if (Match(i))
                    ans++;
                else
                    m[i] = i;
            }
        }
        return ans;
    }
};

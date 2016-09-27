vector<int> g[10000];bool check[10000];int match[10000];int num_left, num_right;
void init(int n)
{
    num_left = num_right = 0;
    for (int i = 0; i < n; i++)g[i].clear();}
bool DFS(int u)
{
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!check[v]) {
            check[v] = true;
            if (match[v] == -1 || DFS(match[v])) /{
                match[v] = u;match[u] = v;return true;
            }
        }
    }
    return false;
}
int Hungarian_DFS() //匈牙利算法
{
    int ans = 0;memset(match, -1, sizeof(match));
    for (int i = 0; i < num_left; i++) {//只要對二分圖的一邊即可
        memset(check, 0, sizeof(check));
        if (DFS(i)) ans++;
    }
    return ans;
}
int Hungarian_BFS()
{
    int prev[10000]; int ans=0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < num_left; i++) {
        memset(check, 0, sizeof(check));
        if (match[i] == -1) {
            queue<int> q; q.push(i);  prev[i] = -1;  bool flag = false;
            while (!q.empty() && !flag) {
                int u = q.front();  q.pop();
                for (int j = 0; j < g[u].size() && !flag; j++) {
                    int v = g[u][j];
                    if (!check[v]) { check[v] = true;
                        if (match[v] != -1) {
                            q.push(match[v]); prev[match[v]] = u;
                        } else {
                            flag = true; int d = u, e = v;
                            while (d != -1) {
                                int t = match[d]; match[d] = e; match[e] = d;
                                d = prev[d]; e = t;
                            }
                        }
                    }
                }
            }
            if (match[i] != -1) ans++;
        }
    }
    return ans;
}

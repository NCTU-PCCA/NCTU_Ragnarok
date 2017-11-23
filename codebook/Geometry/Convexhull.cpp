void ConvexHull(vector<Point>& P, vector<Point>& res)
{
    sort(P.begin(), P.end());
    int cnt = P.size();
    res.resize(cnt+1);
    int m = 0;
    for (int i = 0; i < cnt; i++) {
        while (m > 1 && cross(res[m - 1] - res[m - 2], P[i] - res[m - 2]) <= 0)
            m--;
        res.at(m) = P[i];
        m++;
    }
    int k = m;
    for (int i = cnt - 2; i >= 0; i--) {
        while (m > k && cross(res[m - 1] - res[m - 2], P[i] - res[m - 2]) <= 0)
            m--;
        res.at(m) = P[i];
        m++;
    }
    if (cnt > 1)
        m--;
    res.resize(m);
}
double ConvexHullWidth(vector<Point>& p)
{
    double ans = 1e18;
    int num = p.size();
    for (int i = 0, j = 0; i < num; i++) {
        Line s;
        s.p1 = p[i];
        s.p2 = p[(i + 1) % num];
        while (distance(p[(j + 1) % num], s) >= distance(p[j], s))
            j = (j + 1) % num;
        ans = min(ans, distance(p[j], s));
    }
    return ans;
}

#define next(i) (((i) + 1) % N)
double diameter(vector<Point>& v)
{
    const int N = v.size();
    if (N == 1)
        return 0;
    double maxd = 0;
    Point a, b;
    for (int i = 0, j = 1; i < N; i++) {
        while (dcmp(cross(v[next(i)] - v[i], v[j] - v[i]) - cross(v[next(i)] - v[i], v[next(j)] - v[i])) < 0) {
            j = next(j);
        }
        double d = length(v[i], v[j]);
        if (d > maxd) {
            maxd = d;
            a = v[i];
            b = v[j];
        }
        d = length(v[next(i)], v[next(j)]);
        if (d > maxd) {
            maxd = d;
            a = v[next(i)];
            b = v[next(j)];
        }
    }
    // a, b is the point pair form the diameter
    return maxd;
}

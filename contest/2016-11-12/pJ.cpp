#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
int dcmp(double x)
{
    if (fabs(x) < EPS)
        return 0;
    return x < 0 ? -1 : 1;
}
struct Point {
    double x, y;
    Point() { x = 0, y = 0; }
    Point(double _x, double _y) { x = _x, y = _y; }
    Point operator+(const Point& b)
    {
        return Point(x + b.x, y + b.y);
    }
    Point operator-(const Point& b) const
    {
        return Point(x - b.x, y - b.y);
    }
    bool operator<(const Point& b) const
    {
        return x < b.x || (x == b.x && y < b.y);
    }
    bool operator==(const Point& b)
    {
        return dcmp(x - b.x) == 0 && dcmp(y - b.y) == 0;
    }
};
double cross(Point a, Point b)
{
    return a.x * b.y - b.x * a.y;
}
int ConvexHull(vector<Point>& P, Point* res)
{
    sort(P.begin(), P.end());
    auto last = unique(P.begin(), P.end());
    P.erase(last, P.end());
    int cnt = P.size();
    int m = 0;
    for (int i = 0; i < cnt; i++) {
        while (m > 1 && cross(res[m - 1] - res[m - 2], P[i] - res[m - 2]) <= 0)
            m--;
        res[m++] = P[i];
    }
    int k = m;
    for (int i = cnt - 2; i >= 0; i--) {
        while (m > k && cross(res[m - 1] - res[m - 2], P[i] - res[m - 2]) <= 0)
            m--;
        res[m++] = P[i];
    }
    if (cnt > 1)
        m--;
    return m;
}
double Area(Point* p, int n)
{
    double area = 0;
    for (int i = 0; i < n; i++)
        area += cross(p[i], p[(i + 1) % n]);
    return fabs(area) / 2.0;
}
int main()
{
    int L;
    vector<Point> P;
    Point res[10010];
    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
       double x, y;
        scanf("%lf%lf", &x, &y);
        P.push_back(Point(x, y));
    }
    int m = ConvexHull(P, res);
    int S;
    double area = Area(res, m);
    //printf("%f\n",area);
    scanf("%d", &S);
    int ans = 0;
    for (int i = 0; i < S; i++) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        Point p(x, y);
        double area2 = 0;
        for (int i = 0; i < m; i++)
            area2 += fabs(cross(res[i] - p, res[(i + 1) % m] - p));
        area2/=2.0;

        if (dcmp(area2 -area) == 0)
            ans++;
    }
    printf("%d\n", ans);

    return 0;
}

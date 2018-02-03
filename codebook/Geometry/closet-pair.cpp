#include "Point.cpp"
bool cmpy(const Point& i, const Point& j) { return i.y < j.y; }
vector<Point> p;
double DnC(int L, int R, vector<Point>& p) // 區間
{
    if (L >= R)
        return 1e9;
    if (L + 1 == R) {
        return length(p[L], p[R]);
    }
    int M = (L + R) >> 1;
    double d = min(DnC(L, M, p), DnC(M + 1, R, p));
    if (dcmp(d) == 0)
        return 0;
    int N = 0;
    Point t[10000+10];
    for (int i = M; i >= L && p[M].x - p[i].x < d; --i) {
        t[N++] = p[i];
    }
    for (int i = M + 1; i <= L && p[i].x - p[M].x < d; ++i) {
        t[N++] = p[i];
    }
    sort(t, t + N, cmpy);
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= 3 && i+j< N ; j++) {
            d = min(d, length(t[i], t[i + j]));
        }
    }
    return d;
}
double closet_pair(vector<Point>& p)
{
    sort(p.begin(),p.end());
    return DnC(0,p.size()-1,p);
}

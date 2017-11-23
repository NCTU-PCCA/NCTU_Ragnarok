#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
int dcmp(double x)
{
    if (fabs(x) < EPS)
        return 0;
    else
        return x < 0 ? -1 : 1;
}
struct Point {
    double x, y;
    Point() { x = 0, y = 0; }
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator+(const Point& b)
    {
        return Point(x + b.x, y + b.y);
    }
    Point operator-(const Point& b) const
    {
        return Point(x - b.x, y - b.y);
    }
    Point operator*(double p)
    {
        return Point(x * p, y * p);
    }
    Point operator/(double p)
    {
        return Point(x / p, y / p);
    }
    double operator^(const Point& b) const
    {
        return x * b.y - y * b.x;
    }
    bool operator<(const Point& b)
    {
        return x < b.x || (x == b.x && y < b.y);
    }
    bool operator==(const Point& b)
    {
        return dcmp(x - b.x) == 0 && dcmp(y - b.y) == 0;
    }
};
typedef Point Vector;
double dot(Vector v1, Vector v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}
double cross(Point& o, Point& a, Point& b) //OA X OB
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
double cross(Vector a, Vector b)
{
    return a.x * b.y - a.y * b.x;
}
double length(Vector v)
{
    return sqrt(v.x * v.x + v.y * v.y); //return sqrt(dot(v,v));
}
double length(Point a, Point b)
{
    return length(a - b);
}
double angle(const Vector& a, const Vector& b) { return acos(dot(a, b) / length(a) / length(b)); }
double Triarea(const Point& p1, const Point& p2, const Point& p3)
{
    return fabs(cross(p2 - p1, p3 - p1)) / 2;
}
Vector Rotate(const Vector& a, double rad)
{ //radian 0~2pi //counterclockwise{
    return Vector(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad)); //旋轉矩陣
}
Vector Normal(const Vector& a)
{ //向量的單位法線

    double L = length(a);
    return Vector(-a.y / L, a.x / L);
}
struct Line {
    Point p1, p2;
};
typedef Line Segment;
Point GetLineIntersection(Point p, Vector v, Point q, Vector w) //點斜式交點 p+vt1 q+wt2
{
    Vector u = p - q;
    double t = cross(w, u) / cross(v, w); //t1
    return p + v * t; //p+vt1
}
Point GetLineProjection(Point p, Point a, Point b)
{
    Vector v = b - a;
    return a + v * (dot(v, p - a) / dot(v, v));
}
typedef Line Segment;
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
    int c1 = cross(b1 - a1, b2 - a1), c2 = cross(b1 - a2, b2 - a2);
    int c3 = cross(a1 - b1, a2 - b1), c4 = cross(a1 - b2, a2 - b2);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
bool SegmentProperIntersection(Segment s1, Segment s2)
{
    return SegmentProperIntersection(s1.p1, s1.p2, s2.p1, s2.p2);
}
bool Onsegment(Point p, Point a1, Point a2)
{
    return dcmp(cross(p - a2, a1 - a2)) == 0 && dcmp(dot(a1 - p, a2 - p)) <= 0;
}
bool SegmentIntersection(Point a1, Point a2, Point b1, Point b2)
{
    if (cross(a2 - a1, b2 - b1) == 0)
        return false;
    if (Onsegment(a1, b1, b2) || Onsegment(a2, b1, b2) || Onsegment(b1, a1, a2) || Onsegment(b2, a1, a2))
        return true;
    if (SegmentProperIntersection(a1, a2, b1, b2))
        return true;
    return false;
}
bool SegmentIntersection(Line& l1, Line& l2)
{
    return SegmentIntersection(l1.p1, l1.p2, l2.p1, l2.p2);
}
double distance(Point& a, Point& b)
{
    return sqrt(length(b - a));
}
double distance(Point& p, Line &L) //Line => p1,p2
{
    Vector v1 = p - L.p1, v2 = L.p2 - L.p1;
    return fabs(cross(v1, v2)) / length(v2); //面積/底=高(距離)
}
double distance(Point& p, Segment& s) //Point to Segment
{
    Vector v = s.p2 - s.p1;
    if (dcmp(length(v)) == 0)
        return length(p - s.p1); //線段退化成點
    Vector v1 = p - s.p1;
    Vector v2 = p - s.p2;
    if (dcmp(dot(v1, v)) < 0)
        return length(v1); // 點投影不在線上
    if (dcmp(dot(v2, v)) > 0)
        return length(v2); // 點投影不在線上
    return fabs(cross(v, v1)) / length(v);
}
double distance(Segment& s1, Segment& s2) //線段到線段
{
    if (SegmentIntersection(s1, s2))
        return 0;
    double d = 1e9;
    d = min(d, distance(s1.p1, s2)); //點到線段距離取最短
    d = min(d, distance(s1.p2, s2));
    d = min(d, distance(s2.p1, s1));
    d = min(d, distance(s2.p2, s1));
    return d;
}
double ldistance(Line& l1, Line& l2) //線段到線段距離
{
    Vector v1 = l1.p2 - l1.p1;
    Vector v2 = l2.p2 - l2.p1;
    if (cross(v1, v2) != 0)
        return 0;
    return distance(l1.p1, l2); //點到線段距離
}
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


double PolygonArea(Point* p, int n)
{
    double area = 0;
    for (int i = 0; i < n; ++i)
        area += cross(p[i], p[(i + 1) % n]);
    return fabs(area) / 2;
}
//半平面交
typedef vector<Point> Polygon;
Polygon halfplane_intersection(Polygon& p, Line& line)
{
    Polygon q;
    Point p1 = line.p1, p2 = line.p2;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        double c = cross(p1, p2, p[i]);
        double d = cross(p1, p2, p[(i + 1) % n]);
        if (dcmp(c) >= 0)
            q.push_back(p[i]);
        if (dcmp(c * d) < 0)
            q.push_back(GetLineIntersection(p1, p2, p[i], p[(i + 1) % n]));
    }
    return q;
}

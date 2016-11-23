#include <bits/stdc++.h>
using namespace std;
#define int long long
const double PI = acos(-1.0);
struct Point {
    double x, y;
    Point() {}
    Point(int _x, int _y)
        : x(_x)
        , y(_y)
    {
    }
    Point operator-(const Point& p) const
    {
        return Point(x - p.x, y - p.y);
    }
};
double cross(Point a, Point b)
{
    return a.x * b.y - b.x * a.y;
}
Point right_ans[200000 + 1000];
Point left_ans[200000 + 1000];
Point res[201000];
double get_ans(Point left, Point self, Point right)
{
    int ldx = self.x - left.x;
    int ldy = left.y-self.y;
    int rdx = right.x - self.x;
    int rdy = right.y - self.y;
    double ang = 0;
    double ans = 0;
    if (ldy <= 0) {
        ang += PI/2.0;
    } else{
        ang+=PI/2.0-atan2(ldy,ldx);
    }
    if (rdy <= 0) {
        ang += PI/2.0;
    } else{
        ang+=PI/2.0-atan2(rdy,rdx);
    }
    return ang/(PI)*12.0;
}
#undef int
int main()
{
#define int long long
    int N;
    cin >> N;
    vector<Point> v;
    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        v.push_back(Point(x, y));
    }
    int cnt = v.size();
    int m = 0;
    for (int i = 0; i < cnt; i++) {
        while (m > 1 && cross(res[m - 1] - res[m - 2], v[i] - res[m - 2]) >= 0) {
            m--;
        }
        if (i == 0) {
            left_ans[i] = Point(v[i].x - 1, v[i].y);
        } else {
            left_ans[i] = res[m - 1];
        }
        res[m++] = v[i];
    }
    m = 0;
    for (int i = (cnt - 1); i >= 0; i--) {
        while (m > 1 && cross(res[m - 1] - res[m - 2], v[i] - res[m - 2]) <= 0) {
            m--;
        }
        if (i == (cnt-1)) {
            right_ans[i] = Point(v[i].x + 1, v[i].y);
        } else {
            right_ans[i] = res[m - 1];
        }
        res[m++] = v[i];
    }
    for(int i=0;i<N;i++){
        cout<<fixed<<setprecision(10)<<get_ans(left_ans[i],v[i],right_ans[i])<<endl;
    }
    return 0;
}

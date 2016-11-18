#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265;
const double EPS = 1e-7;
int fcmp(double x)
{
    if (fabs(x) < EPS)
        return 0;
    return (x > 0) ? 1 : -1;
}
struct Point {
    double x, y;
    double angle;
    Point(double _x = 0, double _y = 0, double _angle = 0)
    {
        x = _x;
        y = _y;
        angle = _angle;
    }
    bool operator<(const Point& p) const
    {
        return angle < p.angle;
    }
};

int main()
{
    int N;
    double W, H;
    cin >> N >> W >> H;
    double mx = W / 2.0;
    double my = H / 2.0;
    vector<Point> vu;
    vector<Point> vd;
    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        x -= mx;
        y -= my;
        double ang = atan2(y, x) * 180.0 / PI;
        if (ang < 0)
            vd.push_back(Point(x, y, ang + 180));
        else
            vu.push_back(Point(x, y, ang));
    }
    int half = N / 2;
    sort(vu.begin(), vu.end());
    sort(vd.begin(), vd.end());
    int index = 0;
    int total = vu.size();
    for (int i = 0; i < vu.size(); i++) {
        double ang = vu[i].angle;
        int now = total;
        int line = 0;
        for (; index < vd.size(); index++) {
            if (vd[index].angle <= ang) {
                total++;
                if (fcmp(ang - vd[index].angle) == 0)
                    line++;
            } else
                break;
        }
        int after = total;
        if (after>=half && (after-line)<=half){
            
        }
    }

    return 0;
}

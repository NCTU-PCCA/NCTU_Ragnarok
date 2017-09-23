#define next(i) (((i) + 1) % N)
double diameter(vector<Point>& v)
{
    const int N = v.size();
    if (N == 1)
        return 0;
    double maxd = 0;
    Point a, b;
    for (int i = 0, j = 1; i< N; i++) {
        while (dcmp(v[next(i)] - v[i], v[j] - v[i]) ,cross(v[next(i)] - v[i], v[next(j)] - v[i]))<0) {
            j = next(j);
        }
        double  = dis(v[i], v[j]);
        if (d > maxd) {
            maxd = d;
            a = v[i];
            b = v[j];
        }
        d = dis(v[next(i)], v[next(j)]);
        if (d > maxd) {
            maxd = d;
            a = v[next(i)];
            b = v[next(j)];
        }
    }
    // a, b is the point pair form the diameter
    return maxd;
}

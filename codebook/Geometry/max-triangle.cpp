#include "Point.cpp"

double max_triangle(vector<Point>& points){
    vector<Point> p = ConvexHull(points); // 最大三角形點一定在凸包上
    int n = p.size();
    p.push_back(p[0]);
    double ans = 0;
    for(int i=0; i<n; ++i)
    {
        int j = (i+1)%n;
        int k = (j+1)%n;
        //當Area(P[i], p[j], p[k+1]) <= Area(p[i], p[j], p[k]) 時停止旋轉
        //即Cross(p[j]-p[i], p[k+1]-p[i]) - Cross(p[j]-p[i], p[k]-p[i]) <= 0
        //根據Cross(A,B) - Cross(A,C) = Cross(A,B-C)
        //化簡得Cross(p[j]-p[i], p[k+1] - p[k]) <= 0
        while(k!=i && Cross(p[j]-p[i], p[k+1]-p[k]) > 0)
            k = (k+1) % n;
        if(k==i) continue;
        int kk = (k+1) % n;
        while(j!=kk && k!=i)
        {
            ans = max(ans, Cross(p[j]-p[i], p[k]-p[i]));
            while(k!=i && Cross(p[j]-p[i], p[k+1]-p[k]) > 0)
                k = (k+1) % n;
            j = (j+1) % n;
        }
    }
    return ans*0.5;
}  

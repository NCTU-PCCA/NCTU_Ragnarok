#include "Point.cpp"

void rotating_caliper(vector<Point> P)
{
    sort(P.begin(), P.end());
    int l = 0, u = 0;
    Point L[10000], U[10000];
    int cnt = P.size();
    for (int i = 0; i < cnt; i++) {
        while (l >= 2 && cross(L[l - 2]- L[l - 1],L[l-1]- P[i]) <= 0)
            l--;
        while (u >= 2 && cross(U[u - 2]- U[u - 1], U[u-1]-P[i]) >= 0)
            u--;
        L[l++] = P[i];
        U[u++] = P[i];
    }
    if(u>=2) L[l]=U[u-2];
    for(int i=0,j=u-1;i<l && j>0;){
        //compute L[i] and U[j];
        if(cross(L[i+1]-L[i],U[j-1]-U[j])<=0) i++;
        else j--;
    }
}

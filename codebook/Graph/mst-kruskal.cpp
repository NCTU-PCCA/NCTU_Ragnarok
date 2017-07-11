#include<bits/stdc++.h>
using namespace std;
const int N=20005;
struct Edge{
    int u,v,cost;
    Edge(int _u=0,int _v=0,int _cost=0){
        u=_u,v=_v,cost=_cost;
    }
    bool operator < (const Edge & a) const{
        return cost<a.cost;
    }
};
vector<Edge> E;
int ds[N];
void Init (int n){
    E.clear();
    for(int i=0;i<n;i++) ds[i]=i;
}
int Find(int x){
    return (ds[x]==x)?x:(ds[x]=Find(ds[x]));
}
int kruskal(int n) //point_number;
{
    sort(E.begin(),E.end());
    int ans=0;
    int num=1;
    for( auto &e : E ){
        int u=e.u,v=e.v;
        u=Find(u);v=Find(v);
        if(u!=v){
            ds[u]=v;
            num++;
            ans+=e.cost;
        }
        if(num==n) break;
    }
    return ans;

}


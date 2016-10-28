#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct P
{
    LL x,y,z;
};
LL cnt(LL a ,LL b,LL c)
{
    return sqrt(a*a+b*b+c*c);
}
bool cmp(P a,P b)
{
    return a.x<b.x;
}
int main()
{
    LL n,k;
    while (scanf("%lld%lld",&n,&k) &&(n||k))
    {

        vector<P>v;
        int i;
        for(i=0;i<n;i++)
        {
            LL a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            v.push_back((P){a,b,c});

        }
        sort(v.begin(),v.end(),cmp);

        //printf("%f\n",l);
        int j;
        LL ans=0;
       for(i=0;i<v.size();i++)
       {
           for(j=i+1;j<v.size();j++)
           {
               if(v[j].x-v[i].x>=k) break;
               if(cnt(v[j].x-v[i].x,v[j].y-v[i].y,v[j].z-v[i].z)<k)ans++;
           }
       }
        printf("%lld\n",ans);
    }
    return 0;
}

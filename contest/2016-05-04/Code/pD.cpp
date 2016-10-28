/*************************************************************************
	> File Name: pD.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016/05/11 15:49:23   
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
long long p[1000000+1];
bool check(long long val)
{
    int now=1;
    int people=0;
    while(true)
    {
    long long max_now=LLONG_MIN;
    int num=0;
        int i;
        for(i=now;i<=n;i++)
        {
            max_now=max(max_now,p[i]);
            num++;
            if(max_now*num>val)
            {
                now=now+num-1;
                people++;
                break;
            }
        }
        if(i==n+1) people++;
//        cout<<val<<" "<<people<<" "<<num<<"now= "<<now<<endl;
        if(num==1 && i!=n+1)return false;
        if(people>k)return false;
        if(i==n+1 && people<=k) return true;
    }
}
#undef int
int main()
{
#define int long long
    op_io;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        long long max_d=LLONG_MIN;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
            max_d=max(max_d,p[i]);
        }
        long long l=0;long long r=max_d*n;
        long long ans=r;
        while(l<=r)
        {
            long long mid=(l+r)/2;
  //          cout<<l<<" "<<r<<" "<<mid<<" "<<(int)check(mid)<<endl;
            
            if(check(mid))
            {
                ans=min(ans,mid);
                r=mid-1;
            }else
            {
                l=mid+1;
            }
        
        }
        cout<<ans<<endl;
    }
    return 0;
}

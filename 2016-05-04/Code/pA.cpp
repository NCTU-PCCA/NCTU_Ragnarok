/*************************************************************************
	> File Name: pA2.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016/05/11 19:20:27   
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int T,n;
double dp[1<<20];
double p[20][20];
vector<int> used;
vector<int>used2;
void solve(int nn)
{
    bool uu[1<<20]={};
    if(nn==1) return ;
    double p_match=2.0/(nn*(nn-1));
    for(int t=0;t<used.size();t++)
    {
        int num=used[t];
        for(int i=0;i<n;i++)
        {	
            if((num&(1<<i))==0) continue;
            for(int j=0;j<n;j++)
            {
		if(i==j) continue;
                if((num&(1<<j))==0 ) continue;
                dp[num-(1<<j)]+=p_match*p[i][j]*dp[num];
                if(uu[num-(1<<j)]==false)
                {
                    used2.push_back(num-(1<<j));
                    uu[num-(1<<j)]=true;
                }
            }
        }
        
    }
    used.clear();
    used=used2;
    used2.clear();
    solve(nn-1);
}
int main()
{
  //  op_io;
    cin>>T;
    int kase=0;
    while(T--)
    {
        cin>>n;
memset(p,0,sizeof(p));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>p[i][j];
        }
	memset(dp,0,sizeof(dp));
        dp[(1<<n)-1]=1;
        used.push_back((1<<n)-1);
        solve(n);
	cout<<"Case "<<++kase<<":";
        for(int i=0;i<n;i++)
         printf(" %.6f",dp[1<<i]);
        cout<<endl;
    }

    return 0;
}

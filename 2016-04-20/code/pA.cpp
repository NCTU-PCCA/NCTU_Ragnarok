/*************************************************************************
	> File Name: pA.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016年04月20日 (週三) 19時50分03秒
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
 int N,W,L;
vector<int> v;
int check(int ln)
{   
    int Begin=1;
    int i=0;
    int ans=0;
    while(1)
    {   
        ans++;
        int End=Begin+ln-1;
        if(v[i]>End) {Begin=v[i]; continue;}
        while(i<v.size()&& v[i]<=End) i++;
        Begin=End+1;
        if(i>=v.size()) break;
    }
    if(Begin<=N) ans++;
    return ans;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N>>W>>L;
        v.clear();
        for(int i=1;i<=W;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        int left=1,right=N;
        int ans=N;
        while(left<right)
        {
            int mid=(left+right)/2;
            int m=check(mid);
           // cout<<"mid="<<mid<<" m="<<m<<" left="<<left<<" right="<<right<<endl;
            if(m<=L){ right=mid; ans=min(ans,mid);}
            else left=mid+1;
        }
        
        cout<<ans<<endl;
    }
    return 0;
}
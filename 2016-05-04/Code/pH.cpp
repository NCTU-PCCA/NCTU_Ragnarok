/*************************************************************************
	> File Name: pH.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 廿十六年五月四日 (週三) 十九時廿一分46秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int long long 
int exgcd(int a,int b ,int &x ,int &y, LL s0 = 1, LL s1 = 0, LL t0 = 0, LL t1 = 1)
{
    if(a%b==0)
    {
        x = s1;
        y = t1;
        return b;
    }
    s0-=s1*(a/b);
    t0-=t1*(a/b);
    return exgcd(b,a%b,x,y,s1,s0,t1,t0);
}
#undef int
int main()
{
#define int long long 
    op_io;
    int n;
    while(cin>>n && n)
    {
        int c1,n1,c2,n2;
        cin>>c1>>n1>>c2>>n2;
        int x,y;
        int gcd=exgcd(n1,n2,x,y);
        //cout<<gcd<<" "<<x<<" "<<y<<endl;
        if(n%gcd) cout<<"failed"<<endl;
        else
        {
            x*=(n/gcd);
            y*=(n/gcd);
            int xx=n1/gcd;
            int yy=n2/gcd;
//            cout<<"x="<<x<<" y="<<y<<endl;
  //          cout<<"xx="<<xx<<" yy="<<yy<<endl;
            if(x<0)
            {
             while(x<0)
                {
                x+=yy;
                y-=xx;
                }
                if(y<0)
                {
                    cout<<"failed"<<endl;
                    continue;
                }
            }else if(y<0)
            {
                
             while(y<0)
                {
                x-=yy;
                y+=xx;
                }
                if(x<0)
                {
                    cout<<"failed"<<endl;
                    continue;
                }
            }
            if(c1*yy>c2*xx)
            {
                int t=x/yy;
                x-=yy*t;
                y+=xx*t;
            }else
            {
                int t=y/xx;
                x+=yy*t;
                y-=xx*t;
            }
            cout<<x<<" "<<y<<endl;
        }
    }
    return 0;
}

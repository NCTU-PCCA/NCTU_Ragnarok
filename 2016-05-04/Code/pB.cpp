/*************************************************************************
	> File Name: pB.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 廿十六年五月四日 (週三) 十八時三分七秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;

int main()
{
    op_io;
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int max_x=INT_MIN,min_x=INT_MAX;
        int max_y=INT_MIN,min_y=INT_MAX;
        n*=4;
        while(n--)
        {
            int x,y;
            cin>>x>>y;
            max_x=max(max_x,x);
            max_y=max(max_y,y);
            min_x=min(min_x,x);
            min_y=min(min_y,y);
        }
        cout<<((max_x)-(min_x))*((max_y)-(min_y))<<endl;
    }

    return 0;
}

/*************************************************************************
    > File Name: pD.cpp
    > Author: fuyu0425/a0919610611
    > School: National Chiao Tung University
    > Team: NCTU_Ragnorok
    > Mail: a0919610611@gmail.com
    > Created Time: 西元2016年04月06日 (週三) 17時54分41秒
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long a[3],b[3];
    cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2];
    sort(a,a+3);
    sort(b,b+3);
    if(a[0]==b[0] && a[1]==b[1] && a[1]*a[1]+a[0]*a[0]==b[0]*b[0]+b[1]*b[1]&& a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
    {
        printf("YES\n");
    }else
    {
        printf("NO\n");
    }
    return 0;
}

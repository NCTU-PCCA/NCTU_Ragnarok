/*************************************************************************
    > File Name: pE.cpp
    > Author: fuyu0425/a0919610611
    > School: National Chiao Tung University
    > Team: NCTU_Ragnorok
    > Mail: a0919610611@gmail.com
    > Created Time: 西元2016年04月06日 (週三) 18時01分35秒
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int a[100000+1];
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++) scanf("%d",a+i);
    sort(a+1,a+1+n);
    int ans=INT_MAX;
    for(i=1;i<=n/2;i++) ans=min(ans,a[i]+a[n-i+1]);
    printf("%d\n",ans);
    return 0;
}

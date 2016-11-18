#include<bits/stdc++.h>
using namespace std;

int main()
{
#define int long long 
    int T;
    cin>>T;
    int kase=0;
    while(T--){
        int a=0;
        int b=0;
        int num[7];
        for(int i=0;i<6;i++) cin>>num[i];
        a=1LL*num[0]+2LL*num[1]+3LL*num[2]+3LL*num[3]+4LL*num[4]+10LL*num[5];
        for(int i=0;i<7;i++) cin>>num[i];
       b=1LL*num[0]+2LL*num[1]+2LL*num[2]+2LL*num[3]+3LL*num[4]+5LL*num[5]+10LL*num[6];
        cout<<"Battle "<<++kase<<": ";
        if(a>b){
            cout<<"Good triumphs over Evil"<<endl;
        }else if(a==b){
            cout<<"No victor on this battle field"<<endl;
        }else {
            cout<<"Evil eradicates all trace of Good"<<endl;
        }
       

    }
}

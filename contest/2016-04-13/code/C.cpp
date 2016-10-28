#include<bits/stdc++.h>
using namespace std;
vector<long long>lucky;
long long pow(int a,int b)
{
    long long ans=1;
    long long base=a;
    while(b)
    {
        if(b&1) ans*=base;
        base*=base;
        b>>=1;
    }
    return ans;
}
void build(int n)
{
    //int now=pow(2,n);
    int num=0;

    int i;
    if(n%2==0)
    {
    int now=1<<((n/2));
    for(i=0;i<now;i++)
    {
            long long in=0;
        for(int j=0;j<n/2;j++)
        {
            if(i&(1<<j)) {in+=7*pow(10,j); in+=7*pow(10,n-1-j);}
            else {in+=4*pow(10,j); in+=4*pow(10,n-1-j);}
        }
        lucky.push_back(in);
        num++;
    }
    }else
    {
        int now=1<<((n/2));
        long long in=0;

         for(i=0;i<now;i++)
    {
        in=7*pow(10,n/2);
        for(int j=0;j<n/2;j++)
        {
             if(i &(1<<j)) {in+=7*pow(10,j); in+=7*pow(10,n-1-j);}
            else {in+=4*pow(10,j); in+=4*pow(10,n-1-j);}
        }
        lucky.push_back(in);
        num++;
    }
     for(i=0;i<now;i++)
    {
        in=4*pow(10,n/2);
        for(int j=0;j<n/2;j++)
        {
             if(i &(1<<j)) {in+=7*pow(10,j); in+=7*pow(10,n-1-j);}
            else {in+=4*pow(10,j); in+=4*pow(10,n-1-j);}
        }
        lucky.push_back(in);
        num++;

    }
    }
   // cout<<n<<" "<<num<<endl;

}
int main()
{
    int i;
    for(i=1;i<=18;i++)build(i);
    sort(lucky.begin(),lucky.end());
    lucky.push_back(pow(10,18)+1);
    //cout<<lucky.size();
  //  for(i=0;i<lucky.size();i++)
  //  {
   //     cout<<lucky[i]<<endl;
 //   }
    int T;
    cin>>T;
    while(T--)
    {
        long long L,R;
        cin>>L>>R;
       // cout<<L<<R;
        long long  aa,bb;
        vector<long long> ::iterator ita,itb;
        ita=lower_bound(lucky.begin(),lucky.end(),L);
        itb=lower_bound(lucky.begin(),lucky.end(),R);
        aa=ita-lucky.begin();
        bb=itb-lucky.begin();

       // if(itb==lucky.end()) bb=lucky.size()-1;

        if(lucky[bb]>R) bb--;
      //  cout<<aa<<" "<<bb<<endl;
        cout<<bb-aa+1<<endl;
        }
}

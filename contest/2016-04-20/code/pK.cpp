#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ExGCD(LL A,LL B,LL& X,LL& Y,LL s0 = 1,LL s1 = 0,LL t0 = 0,LL t1 = 1){
  if(A%B == 0){
    X = s1;
    Y = t1;
    return B;
  }
  s0-=s1*(A/B);
  t0-=t1*(A/B);
  ExGCD(B,A%B,X,Y,s1,s0,t1,t0);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int a, b, c;
        //scanf("%d%d%d", &a, &b, &c);
	cin>>a>>b>>c;
        LL x, y;
        LL gcd = ExGCD(a,-b,x,y);
        x *= c / gcd;
        y *= -c / gcd;
	a=a/gcd;
	b=b/gcd;
        //cout<<"x= "<<x<<" y="<<y<<endl;
        while(y>0)
        {
            x+=b;
            y-=a;
        }
        while(x<=0 || y<=0 )
        {
            x -= b;
            y += a;
        }
        cout << x << ' ' << y << endl;
    }
    return 0;
}
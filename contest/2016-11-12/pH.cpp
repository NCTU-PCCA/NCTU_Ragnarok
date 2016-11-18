#include <bits/stdc++.h>
using namespace std;
#define int long long
int cal(string in)
{
    int ans = 0;
    for (int i = 0; i < in.size(); i++) {
        ans *= 2;
        ans += (in[i] - '0');

    }
    return ans;
}
#undef int
int main()
{
#define int long long
    int x, y;
    cin >> x >> y;
    map<int,bool> m;
    int ans = 0;
    for (int i = 1; i <= 63; i++) {
        for (int j = 1; j <= 63; j++) {
            string num = "";
            for (int t = 0; t < i; t++)
                num += '1';
            int xx=0;
            while (num.size() <= 63) {
            int c = cal(num);
            if (c >= x && c <= y && !m[c]){
            //cerr<<num<<" "<<c<<" "<<i<<" "<<j<<endl;
                
                m[c]=1;
                ans++;
            }
                if (xx % 2) {
                    for (int t = 0; t < i; t++)
                        num += '1';
                } else {
                    for (int t = 0; t < j; t++)
                        num += '0';
                }
                xx++;
            }
        }
    }
        cout<<ans<<endl;
}

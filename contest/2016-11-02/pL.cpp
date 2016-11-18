#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int x, y, z;
    x = 0, y = 0, z = 0;
    while (T--) {
        int xx, yy, zz;
        cin >> xx >> yy >> zz;
        x += xx;
        y += yy;
        z += zz;
        int min_v = x;
        int min2 = min(y, z);
        min_v = min(min_v, min2);
        if (min_v < 30) {
            cout << "NO" << endl;
            continue;
        }
        cout<<min_v<<endl;
        x-=min_v;
        y-=min_v;
        z-=min_v;
    }
}

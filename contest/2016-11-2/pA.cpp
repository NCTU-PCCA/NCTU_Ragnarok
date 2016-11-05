#include<bits/stdc++.h>
using namespace std;

int main()
{
    string in;
    while(cin>>in){
        for(int i=0;i<in.size();i+=2){
            stringstream ss;
            ss<<in[i]<<in[i+1];
            int a;
            ss>>hex>>a;
            cout<<(char) a;
        }
        cout<<endl;
    }
    return 0;
}

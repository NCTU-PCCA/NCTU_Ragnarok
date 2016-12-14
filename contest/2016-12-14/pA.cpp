#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int low=INT_MAX,big=0;
    int ans=0;
    deque<int> q;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        if(t<low) {
            q.push_front(t);
            low=t;
            big=max(low,t);
            ans++;
        }else if(t>big){
            q.push_back(t);
            big=t;
            low=min(low,t);
            ans++;
        }else if(t==low){
            q.push_front(t);
            ans++;
        }else if(t==big ) {
            q.push_back(t);
            ans++;
        }
        
    }
    return 0;
}

/*************************************************************************
	> File Name: pL.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016年04月20日 (週三) 18時29分25秒
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        int d;
        int f;
        int import=0;
        cin>>f;
        while(cin>>d && d)
        {
            if(d>=2*f)
            {
                import+=d-2*f;
            }
           f=d; 
		          
        }
        cout<<import<<endl;
    }
    return 0;
}
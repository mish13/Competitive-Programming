#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        vector <pair<int,int> > vt;
        for(int i=1;i<=n;i++)
        {
            int s,e;
            cin>>s>>e;
            vt.push_back({e,s});
        }
        sort(vt.begin(),vt.end());
        int cnt=1,now=vt[0].first;
        for(int i=1;i<vt.size();i++)
        {
            if(vt[i].second>=now)
            {
                cnt++;
                now = vt[i].first;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

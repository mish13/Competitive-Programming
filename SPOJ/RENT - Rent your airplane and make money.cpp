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
        vector < pair <int, pair <int,int> > > vt;
        int s,d,wt;
        for(int i=1;i<=n;i++)
        {
            cin>>s>>d>>wt;
            vt.push_back({s+d,{s,wt}});
        }
        sort(vt.begin(),vt.end());
        int res[n+7];
        for(int i=0;i<vt.size();i++)
            res[i]=vt[i].second.second;
        for(int i=1;i<vt.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(vt[j].first<vt[i].second.first)
                {
                    res[i]=max(res[i],res[j]+vt[i].second.second);
                }
            }
        }
        int mx =-1;
        for(int i=0;i<vt.size();i++)
        {
            if(res[i]>mx)
                mx=res[i];
        }
        cout<<mx<<endl;

    }
    return 0;
}

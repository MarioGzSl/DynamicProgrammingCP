#include <bits/stdc++.h>
using namespace std;
#define sz int(1e5+1)
int main()
{
    string s1, s2;

    cin>>s1>>s2;
    s1='0'+s1;
    s2='0'+s2;
    int n=s1.size(), m=s2.size();
    
    vector < vector<int> > dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(s1[i]==s2[j]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    int y=n-1,x=m-1;
    string s = "";
    while(dp[y][x]){
        int mxx = max(dp[y-1][x-1], max(dp[y-1][x], dp[y][x-1]));
        if(mxx!=dp[y][x]){
            s=s1[y]+s;
            y--, x--;
        }else{
            if(dp[y-1][x]==dp[y][x])
                y--;
            else if (dp[y-1][x-1]==dp[y][x]){
                y--, x--;
            }else{
                x--;
            }
        }
    }

    cout<<s<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define sz int(1e5+1)
int main()
{
    int N, W; cin >> N >> W;
    int vi,wi;

    
    vector <long long> dp (sz+1, INT_MAX);
    dp[0]=0;
    int sum=0;
    for(int i = 0; i < N; i++){
        cin >> wi >> vi;
        sum+=vi;
        for(int j = sz; j >= vi; j--){
            dp[j] = min(dp[j], dp[j-vi]+wi);
        }
    }
    int ans=0;
    for(int i = 1; i <= sum; i++){
        if(dp[i]<=W)
            ans=max(i, ans);
    }
    cout<<ans<<endl;



    return 0;
}
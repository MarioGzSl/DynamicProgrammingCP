#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N, W; cin >> N >> W;
    int vi,wi;

    vector <long long > dp (W+1, 0);

    for(int i = 0; i < N; i++){
        cin >> wi >> vi;
        for(int j = W; j >= wi; j--){
            dp[j] = max (dp[j], dp[j-wi] + vi);
        }
    }
    cout << dp[W] << "\n";
    



    return 0;
}
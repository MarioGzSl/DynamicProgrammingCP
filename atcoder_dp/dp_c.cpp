#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    int N;
    cin>>N;
    vector<vector<int> > V(N, vector<int>(3)), dp(N, vector<int>(3,0));
    for(int i=0;i<N;i++)
        cin>>V[i][0]>>V[i][1]>>V[i][2];
    dp[0]=V[0];
    for(int i=1;i<N;i++)
        for(int j=0;j<3;j++)
            dp[i][j]=V[i][j]+max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);    
    cout<<max(max(dp[N-1][0], dp[N-1][1]), dp[N-1][2])<<endl;
    return 0;
}
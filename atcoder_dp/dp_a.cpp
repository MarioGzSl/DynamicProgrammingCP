#include <iostream>
#include <vector>
using namespace std;
int min(int& a, int& b){return a<b?a:b;}
void memo(int target, vector<int>& V, vector<int>& dp){
    dp[0]=0;
    dp[1]=abs(V[1]-V[0]);
    for(int i=2;i<target;i++){
        dp[i]=min(dp[i-1]+abs(V[i]-V[i-1]), dp[i-2]+abs(V[i]-V[i-2]));
    }
}
int main(){
    int N;
    cin>>N;
    vector<int> V(N, 0);
    vector<int> dp(N, 0); 
    for(int i=0;i<N;i++)cin>>V[i];
    memo(N, V, dp);
    cout<<dp[N-1]<<endl;
    return 0;
}

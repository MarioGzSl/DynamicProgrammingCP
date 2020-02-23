#include <iostream>
#include <vector>
using namespace std;
int min(int& a, int& b){return a<b?a:b;}
void pre_calc(int target, vector<int>& V, vector<int>& dp){
    
    dp[0]=0;
    dp[1]=abs(V[1]-V[0]);

    for(int i=2;i<target;i++){
        dp[i]=min(dp[i-1]+abs(V[i]-V[i-1]), dp[i-2]+abs(V[i]-V[i-2]));
    }
}
int main(){
    int N;
    vector<int> V;
    vector<int> dp;

    
    cin>>N;
    V.assign(N,0);
    dp.assign(N,0);
    for(int i=0;i<N;i++)cin>>V[i];
    pre_calc(N, V, dp);

    cout<<dp[N-1]<<endl;


    return 0;
}
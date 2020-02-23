#include <iostream>
#include <vector>
using namespace std;
int min(int& a, int& b){return a<b?a:b;}
void memo(int&, int&, vector<int>&, vector<int>&);
int main(){
    int N, K;
    
    cin>>N>>K;
    vector<int> V(N, 0);
    vector<int> dp(N, INT32_MAX);

    for(int i=0;i<N;i++)cin>>V[i];
    memo(N, K, V, dp);

    cout<<dp[N-1]<<endl;


    return 0;
}

void memo(int& n, int& k, vector<int>& V, vector<int>& dp){ 
    dp[0]=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            int pos = i-j;
            if(pos<0)break;
            dp[i]=min(dp[i], dp[pos]+abs(V[i]-V[pos]));
        }
    }
}

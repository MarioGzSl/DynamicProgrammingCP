#include <iostream>
#include <vector>
using namespace std;

// Function to return the minimum of two numbers.
// This is a custom version of the std::min function.
int min(int& a, int& b){return a<b?a:b;}

// Function to perform "memoization", or storage of intermediate results. 
void memo(int target, vector<int>& V, vector<int>& dp){
    dp[0]=0; // Cost of the first stone is 0, as we start from here
    dp[1]=abs(V[1]-V[0]); // Cost of the second stone is the absolute difference between the first and second stones

    // We iterate over the stones from the third one
    for(int i=2;i<target;i++){
        // We calculate the minimum cost to reach the current stone.
        // We have two options: 
        // 1. Jump from the previous stone (dp[i-1]+abs(V[i]-V[i-1]))
        // 2. Jump from the stone before the previous one (dp[i-2]+abs(V[i]-V[i-2]))
        // We select the minimum of these two options.
        dp[i]=min(dp[i-1]+abs(V[i]-V[i-1]), dp[i-2]+abs(V[i]-V[i-2]));
    }
}

int main(){
    int N; // Number of stones
    cin>>N; // We read the number of stones

    // We create the vector V of stones and dp of costs with size N
    vector<int> V(N, 0);
    vector<int> dp(N, 0); 

    // We read the heights of the stones
    for(int i=0;i<N;i++)cin>>V[i];

    // We call the memoization function
    memo(N, V, dp);

    // We print the minimum cost to reach the last stone
    cout<<dp[N-1]<<endl;

    return 0;
}

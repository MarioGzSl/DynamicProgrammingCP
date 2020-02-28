#include <bits/stdc++.h> 

using namespace std;
#define mod int(1e9+7)

int H, W;
void dfs(vector< vector<char> >& M, vector< vector<int> >& dp, vector< vector<int> >& visited, int y, int x){
    if(visited[y][x]==1)return;
    if(y==H-1 and x==W-1){dp[y][x]=1;return;}

    if(y+1<H and M[y+1][x]!='#'){
        dfs(M, dp, visited, y+1, x);
        dp[y][x]=(dp[y][x]+dp[y+1][x])%mod;
    }

    if(x+1<W and M[y][x+1]!='#'){
        dfs(M, dp, visited, y, x+1);
        dp[y][x]=(dp[y][x]+dp[y][x+1])%mod;
    }

    visited[y][x]=1;
}
int main(){
    cin>>H>>W;
    vector< vector<char> > M(H, vector<char>(W,'.'));
    vector< vector<int> > dp(H, vector<int>(W,0));
    vector< vector<int> > visited(H, vector<int>(W,0));
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            cin>>M[i][j];
        
    dfs(M, dp, visited, 0, 0);

    cout<<dp[0][0]<<endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
struct node{
    node(int i){label = i;}
    int label;
    vector< node* > adj;
};
vector<int> visited;
vector<int> dp;
void dfs(node* crr){
    //cout<<crr->label<<endl;
    if(visited[crr->label])return;
    if(crr->adj.size()==0){dp[crr->label]=1;return;}
    int mxx=INT_MIN;
    for(node* nd: crr->adj){
        if(nd==NULL)continue;
        //cout<<crr->label<<"->"<<nd->label<<endl;
        dfs(nd);
        mxx=max(mxx,dp[nd->label]);
    }
    dp[crr->label]=mxx+1;
    visited[crr->label]=1;
}
int main(){
    int N, M, n1, n2;
    cin>>N>>M;
    visited.assign(N+1,0);
    dp.assign(N+1,0);
    vector< node* > nodes;
    for(int i=0;i<N+1;i++)nodes.push_back(new node(i));
    for(int i= 0;i<M;i++){
        cin>>n1>>n2;
        nodes[n1]->adj.push_back(nodes[n2]);
    }
    for(node* nd:nodes)dfs(nd);
    int ans=INT_MIN;
    for(int i=1; i<=N; i++){
        //cout<<dp[i]<<endl;
        ans=max(ans, dp[i]);
    }
    cout<<ans-1<<endl;
    return 0;
}
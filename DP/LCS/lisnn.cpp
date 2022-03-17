//Longest increasing subsequence in N*N complexity
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &x:v)
        cin>>x;
    int dp[n+1],ans=0;
    memset(dp,1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[j] < v[i]){
                dp[i]=max(dp[i],dp[j]+1);
                ans=max(ans,dp[i]);
            }
        }
    }
    cout<<"The size of the longest increasing subsequence in n*n complexity is "<<ans<<"\n";
    return;
}
#include<iostream>

using namespace std;

int N,M,ans;
int arr[105];
int dp[10005];
inline int MIN(int a,int b){return a<b?a:b;}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<10005;i++)dp[i]=100001;
	cin >> N >> M;
	for(int i=0;i<N;i++) cin>> arr[i];
//	for(int i=1;i<M+1;i++) cout << i << "\t";
//	cout << endl;
	dp[0]=0;
	for(int i=1;i<N+1;i++)
		for(int j=arr[i];j<M+1;j++)
			dp[j]=MIN(dp[j],dp[j-arr[i]]+1);
	
	if(dp[M]==100001) cout << -1;
	else cout << dp[M];
	
	return 0;
}

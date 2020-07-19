#include<iostream>
#include<algorithm>
using namespace std;

int N,M,ans;
int arr[105];
int dp[100005];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for(int i=0;i<N;i++) cin>> arr[i];
	dp[0]=1;
	for(int i=0;i<N;i++){
		for(int j=1;j<M+1;j++){
			if(j>=arr[i]) dp[j]+=dp[j-arr[i]];
		}
	}
	cout << dp[M];
	
	return 0;
}

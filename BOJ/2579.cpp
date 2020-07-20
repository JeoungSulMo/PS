#include<iostream>
using namespace std;

int n,arr[305],dp[305];

int mmax(int a, int b){
	return a>b?a:b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	dp[0]=arr[0];
	dp[1]=mmax(arr[0],dp[0]+arr[1]);
	dp[2]=mmax(arr[0]+arr[2],arr[1]+arr[2]);
	for(int i=3;i<n;i++)
		dp[i]=mmax(dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]);
	
	cout << endl << dp[n-1];
	
	return 0;
}

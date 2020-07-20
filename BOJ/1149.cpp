	#include<iostream>
	#include<algorithm>
	using namespace std;	
	
	int arr[1005][3];
	int dp[1005][3];
	int n,i,j;
	
	int MIN(int a,int b){
		return a<b?a:b;
	}
	
	int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cin.tie(NULL);
		cin >> n;
		for(i=0;i<n;i++)
			for(j=0;j<3;j++)
				cin >> arr[i][j];
		
		dp[0][0]=arr[0][0];
		dp[0][1]=arr[0][1];
		dp[0][2]=arr[0][2];
		
		for(i=1;i<n;i++){
			dp[i][0]=MIN(arr[i][0]+dp[i-1][1],arr[i][0]+dp[i-1][2]);
			dp[i][1]=MIN(arr[i][1]+dp[i-1][0],arr[i][1]+dp[i-1][2]);
			dp[i][2]=MIN(arr[i][2]+dp[i-1][0],arr[i][2]+dp[i-1][1]);
		}
		int minn=1000001;
		
		for(i=0;i<3;i++){
			cout<< dp[n-1][i] << endl;
			if(minn>dp[n-1][i])minn=dp[n-1][i];
		}
		cout << minn;
		return 0;
	}

#include<stdio.h>
#include<algorithm>

int dp[1005];
int n;

int dpf(int x){
	if(dp[x]) return dp[x];
	if(x==1) return dp[1]=1;
	if(x==2) return dp[2]=2;
	return dp[x]=(dpf(x-1)+dpf(x-2))%10007;
}

int main(){
	scanf("%d",&n);
  int ans = dpf(n);
	printf("%d",ans);
	
	return 0;
}

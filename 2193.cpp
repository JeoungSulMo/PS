#include<iostream>

using namespace std;
typedef long long ll;
int n;
ll buf[100];
ll dp(int cur){
	if(buf[cur]!=0) return buf[cur];
	if(cur==0) return buf[cur]=1;
	if(cur==1) return buf[cur]=1;
	if(cur==2) return buf[cur]=2;
	return buf[cur]=dp(cur-2)+dp(cur-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cout << dp(n-1);
	
	return 0;
}

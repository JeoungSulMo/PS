#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll arr[10005];
ll s=1,e,mid,bufN,bufN2;
int K,N,i,minn=1000000,b,minV;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);	
	
	cin >> K >> N;
	for(i=0; i<K; i++) {
		cin >> arr[i];		
		if(e < arr[i]) e=arr[i];
	}
	
	while(s<=e){
		bufN=0;
		mid=(s+e)/2;
		for(i=0; i<K; i++) bufN+=arr[i]/mid;
		if(bufN<N) e=mid-1;
		else if(bufN>=N) {
			s=mid+1;
		}
		b=bufN-N;
		if(minn>=b&&b>=0) minn=b,minV=mid;
	}
	cout << minV;
	return 0;
}

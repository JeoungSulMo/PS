#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int arr[1000005];
int M,n,m,i,s=0,e=1000000000;
ll tm;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);	
	
	cin >> n >> M;
	for(i=0; i<n; i++) cin >> arr[i];	
	
	while(s<=e){
		m=(s+e)/2;
		tm=0;
		for(i=0; i<n; i++){
			if(arr[i]-m>0)tm += arr[i]-m;	
		}
		printf("%d만큼 남기고 얻은  %d\n",m,tm);
		if(M==tm){
			printf("%d",m);
			return 0;
		}
		else if(M>tm){
			e=m-1;
		}else if(M<tm){
			s=m+1;
		}
	}
	if(tm<M)printf("%d\n",m-1);
	else printf("%d\n",m);
	
	return 0;
}

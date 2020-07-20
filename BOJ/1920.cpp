#include<iostream>
#include<algorithm>
using namespace std;

int arr[100005];
int i,j,n,m;

int process(int b);

int main(){
	ios_base::sync_with_stdio(false);
cin.tie(NULL);
	cin >> n;
	for(i=0;i<n;i++) cin >> arr[i];
	sort(arr,arr+n);
	cin >> m;
	for(i=0;i<m;i++){
		cin >> j;
		printf("%d\n",process(j));
	} 
	return 0;
}

int process(int b){
	int start=0, end=n-1,target;
	while(1){
		target=(start+end)/2;
		if(arr[target]==j) return 1;
		if(start>=end){
			return 0;
		} 
		else if(arr[target]<b){
			start=target+1;
		}else if(arr[target]>b){	
			end=target-1;
		}
		
	}
	
}

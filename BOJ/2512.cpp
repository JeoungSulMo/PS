#include<iostream>
#include<algorithm>

using namespace std;

int N,M,i,arr[10005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(i=0;i<N;i++) cin >> arr[i];
	cin >> M;
	sort(arr,arr+N);
	int mmaxIdx=0,re=0,asIdx=0,eIdx=0,avg;
	while(1){
		if(N!=asIdx){
			avg = M/(N-asIdx);	
		}else {
			cout << arr[N-1];
			return 0;
		}
		// 평균이 아에 작거나 클때 
		if(avg<arr[asIdx]) {
			cout << avg;
			return 0;
		}else if(avg>arr[N-1]){
			cout << arr[N-1];
			return 0;
		} 
		while(1){
			if(arr[mmaxIdx]>avg){
				mmaxIdx -= 1;
				break;
			}else if(arr[mmaxIdx]==avg) break;
			mmaxIdx++;
		}
		for(i=asIdx;i<mmaxIdx+1;i++) M-=arr[i];
		mmaxIdx++;
		asIdx=mmaxIdx;
	}	
	return 0;
}

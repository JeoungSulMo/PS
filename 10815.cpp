#include<iostream> 
#include<algorithm>
using namespace std;

int N,M,i,Narr[500005],Marr[500005],MV,s,e,mid;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);	
	
		cin >> N;
	for(i=0; i<N; i++) {
		cin >> Narr[i];		
	}
	
	cin >> M;
	
	sort(Narr,Narr+N);
	for(i=0; i<M; i++) {
		cin >> MV;
		s=0,e=N-1;
		while(s<=e){
			mid=(s+e)/2;
			if(Narr[mid]==MV) {
				Marr[i]=1;
				break;	
			}else if(Narr[mid]<MV)s=mid+1;
			else if(Narr[mid]>MV) e=mid-1;
		}
		if(Narr[mid]!=MV)Marr[i] = 0;
	}		
	for(i=0;i<M;i++){
		cout << Marr[i];
		if(i!=M-1) cout<< " ";
	}
	
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

int N,i,j,num=2,cnt;
int arr[31][31];
int arr1[31];
void process(int a, int b,int c);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cin >> arr[i][j];
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
				cnt=0;
				if(arr[i][j]==1)process(i,j,num);
				if(cnt!=0) num++;
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;	
	}
	
	return 0;
}

bool check(int a,int b){
	return (b<N&&b>=0&&a<N&&a>=0);
}

void process(int a,int b, int c){
	if(arr[a][b]==0) return;
	arr[a][b]=c;
	cnt++;
	if(check(a,b+1)&&arr[a][b+1]==1)process(a,b+1,c);
	if(check(a+1,b)&&arr[a+1][b]==1)process(a+1,b,c);
	if(check(a-1,b)&&arr[a-1][b]==1)process(a-1,b,c);
	if(check(a,b-1)&&arr[a][b-1]==1)process(a,b-1,c);
}

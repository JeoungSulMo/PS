# include <iostream>
using namespace std;
int n;
int arr[1000050];
void fibo(){
	arr[0]=1;
	arr[1]=1;
	for(int i=2;i<1000001;i++){
		arr[i]=arr[i-1]%15746+arr[i-2]%15746;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	fibo();
	cout << arr[n];
	
	return 0;
}

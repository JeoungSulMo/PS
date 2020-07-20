#include<iostream>

using namespace std;

int k=1,count;
int arr[100][15];
int buf[10];
int k_arr[100];

void _print(){
	for(int i=0;i<6;i++)
		cout << buf[i] << " ";
	cout << endl;
}

void dfs(int indx,int cnt,int cnt_col){
	if(cnt!=-1) buf[cnt]=arr[cnt_col][indx];
	if(cnt==5){
		_print();
		return;
	}
	for(int i=indx;i<k_arr[cnt_col]-1;i++)
		dfs(i+1,cnt+1,cnt_col);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

		while(1) {
			cin >> k;
			if(k==0)break;
			for(int i=0;i<k;i++)
					cin >> arr[count][i];
			k_arr[count]=k;
			count++;
		}
	
		for(int i=0;i<count;i++){
			dfs(-1,-1,i);
			if(i!=count-1)cout << endl;
		}
    return 0;
}

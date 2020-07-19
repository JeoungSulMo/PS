#include<iostream>
#include<algorithm>
using namespace std;

typedef struct ch{
	int location,value=0;
}ch;

ch arr[10][10];
int col[10];
int low[10];
//Queen count: Qcnt,  Color count: Ccnt,  LocationNum : Lnum
int i,j,N;

bool check(int a,int b){
	return (b<N && b>=0 && a<N && a>=0);
}

void resett(){
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			arr[i][j].value=0;
		}
	}
}

void dfs(int a,int b,int d){
	arr[a][b].value=1;
//	for(int ii=0;ii<N;ii++){
//		for(int jj=0;jj<N;jj++){
//			printf("%d ",arr[ii][jj].value);
//		}
//		cout<< endl;
//	}cout<< endl;
	switch(d){
		case 0:
			if(check(a,b+1)) dfs(a,b+1,1);// 오 
			if(check(a+1,b+1)) dfs(a+1,b+1,2); //오 아 
			if(check(a+1,b)) dfs(a+1,b,3); // 아 
			if(check(a+1,b-1)) dfs(a+1,b-1,4); // 아 왼 
			if(check(a,b-1)) dfs(a,b-1,5); // 아 
			if(check(a-1,b-1)) dfs(a-1,b-1,6);
			if(check(a-1,b)) dfs(a-1,b,7);
			if(check(a-1,b+1)) dfs(a-1,b+1,8);
			break;
		case 1:
			if(check(a,b+1)) dfs(a,b+1,1);
			break;
		case 2:
			if(check(a+1,b+1)) dfs(a+1,b+1,2);
			break;
		case 3:
			if(check(a+1,b)) dfs(a+1,b,3);
			break;
		case 4:
			if(check(a+1,b-1)) dfs(a+1,b-1,4);
			break;
		case 5:
			if(check(a,b-1)) dfs(a,b-1,5);
			break;
		case 6:
			if(check(a-1,b-1)) dfs(a-1,b-1,6);
			break;
		case 7:
			if(check(a-1,b)) dfs(a-1,b,7);
			break;
		case 8:
			if(check(a-1,b+1)) dfs(a-1,b+1,8);
			break;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			arr[i][j].location=Lnum++;
		}
	}
	
	for(i=0;i<N;i++){
		dfs(i,cnt,0);
		cnt++;
	}

	return 0;
}


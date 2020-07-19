#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
int n,m,mmax;
int arr[11][11];
int visited[11][11];

typedef struct point{
	int x,y;
}point;

void reset(){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			visited[i][j]=arr[i][j];
}

bool safe(int a,int b){
	return (a<n&&a>=0&&b<m&&b>=0);
}
int tx[]={1,-1,0,0};
int ty[]={0,0,1,-1};
void bfs(){
	point cur;
	queue<point> Q;
	reset();
	// 바이러스 위치 찾기 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visited[i][j]==2) Q.push({i,j});
			
		}	
	}	
	// 바이러스 퍼트리기 
	while(!Q.empty()){
		cur=Q.front();Q.pop();
		for(int i=0;i<4;i++){
			int nx=cur.x+tx[i];
			int ny=cur.y+ty[i];
			if(safe(nx,ny)&&visited[nx][ny]==0){
				visited[nx][ny]=2;
				Q.push({nx,ny});
			}
		}
	}
	int zero=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visited[i][j]==0) zero++;
		}	
	}	
	if(mmax<zero) mmax=zero;
}
void dfs(int a){
	if(a==3){
		bfs();
		return;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==0){
				arr[i][j]=1;
				a++;
				dfs(a);
				arr[i][j]=0;
				a--;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> arr[i][j];
			
	// 0에 순차적으로 벽 3개 세우기
	dfs(0);
	cout << mmax;
	return 0;
}

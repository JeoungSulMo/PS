#include<stdio.h>
#include<queue>

int nums[11][11];
int visited[11][11];
int n,minn=1001;
typedef struct Qstruct{
	int x=-1,y=-1;
	int Rarr[11]={0,0,0,0,0,0,0,0,0,0,0};
	int cnt=-1;
}Qstruct;


void bfs(int a,int cnt,int c){
	
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&nums[i][j]);
	queue<Qstruct> Q;
	Qstruct start;
	Q.push(start);
	while(!Q.empty()){
		Qstruct cur = Q.front();Q.pop();
		for(int i=0;i<n;i++){
			if(!cur.Rarr[i]){
				cur.x=cnt
			}
		}
	}
	printf("%d",minn);
	return 0;
}
	

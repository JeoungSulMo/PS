#include<stdio.h>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int r,c,i,j,sx,sy,gx,gy,arr[101][101];
char buf[101][101];
typedef struct point{
	int x,y;
}point;
bool safe(int a,int b){
	return (a>=0 && a<r && b>=0 && b<c);
}
int tx[]={-1,1,0,0};
int ty[]={0,0,-1,1};
int main() {
	// input();
	scanf("%d %d", &r, &c);
	for(i=0;i<r;i++){
		scanf("%s",&buf[i]);
		for(j=0;j<c;j++){
			if(buf[i][j]=='#') arr[i][j]=-1;
			else if(buf[i][j]=='S') sx=i,sy=j;
			else if(buf[i][j]=='G') gx=i,gy=j,buf[i][j]='.';
		}
	}
	// solve();
	queue<point> Q;
	Q.push((point){sx,sy}), arr[sx][sy]=0;
	while(!Q.empty()){
		point cur = Q.front();Q.pop();
		if(cur.x==gx&&cur.y==gy) break;
		for(i=0;i<4;i++){
			int a=cur.x+tx[i];
			int b=cur.y+ty[i];
			if(safe(a,b)&&!arr[a][b]&&buf[a][b]=='.'){
					arr[a][b]=arr[cur.x][cur.y]+1;
					Q.push((point){a,b});
			}
		}
	}
	printf("%d",arr[gx][gy]);
	return 0;
}

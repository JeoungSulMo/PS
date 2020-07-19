#include<stdio.h>
#include<queue>

int nums[11][11];
int visited[11][11];
int Carr[11];
int n,minn=1001;
typedef struct point{
	int x,y;
}point;


void dfs(int a,int cnt,int c){
	cnt++;
	for(int j=0;j<n;j++){
		if(!Carr[j]){
			Carr[j]=1;
			//printf("visi[%d][%d] :%d // a: %d   ",cnt,j,visited[cnt][j],a);
			visited[cnt][j]+=a;
			//printf("visited[cnt][j] %d \n",visited[cnt][j]);
			if(cnt==n-1){
				if(minn>visited[cnt][j]) minn=visited[cnt][j];
				//printf("minn: %d \n",minn);
				visited[cnt][j]-=a;
				cnt-=1;
				Carr[j]=0;
				return ;
			}
			dfs(visited[cnt][j],cnt,j);	
			//printf("cnt :%d À¸·Î\n",cnt+1);
			visited[cnt][j]-=a;
			Carr[j]=0;
		}
	}		
	
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&nums[i][j]);
			visited[i][j]=nums[i][j];
		}
	}
	dfs(0,-1,0);
	printf("%d",minn);
	return 0;
}
	

#include<iostream>
#include<algorithm>
using namespace std;

typedef struct ch{
	int location,value=0;
}ch;

ch arr[10][10];
//Queen count: Qcnt,  Color count: Ccnt,  LocationNum : Lnum
int i,j,k,l,m,N,cnt,Qcnt,Ccnt,Lnum=1,ttry;
int Tbuf[82],TbufI,buf[10],bufI,place;

bool check(int a,int b){
	return (b<N && b>=0 && a<N && a>=0);
}
bool check2(int a){
	for(int t=0;t<N*N;t++){
		if(Tbuf[t]==a) 	return false;
	}
	return true;
}

void resett(){
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			arr[i][j].value=0;
		}
	}
//	cout << "»©¾×" <<endl;
	Qcnt=0;
	bufI=0;
}

void dfs(int a,int b,int c,int d){
	arr[a][b].value=1;
	if(Qcnt==N) return;// ¿Ï¼º½Ã 
	if(Qcnt<N&&Ccnt>=N*N) return;	
	switch(d){
		case 0:
			if(check(a,b+1)) dfs(a,b+1,c++,1);// ¿À 
			if(check(a+1,b+1)) dfs(a+1,b+1,c++,2); //¿À ¾Æ 
			if(check(a+1,b)) dfs(a+1,b,c++,3); // ¾Æ 
			if(check(a+1,b-1)) dfs(a+1,b-1,c++,4); // ¾Æ ¿Þ 
			if(check(a,b-1)) dfs(a,b-1,c++,5); // ¾Æ 
			if(check(a-1,b-1)) dfs(a-1,b-1,c++,6);
			if(check(a-1,b)) dfs(a-1,b,c++,7);
			if(check(a-1,b+1)) dfs(a-1,b+1,c++,8);
			break;
		case 1:
			if(check(a,b+1)) dfs(a,b+1,c,1);
			break;
		case 2:
			if(check(a+1,b+1)) dfs(a+1,b+1,c++,2);
			break;
		case 3:
			if(check(a+1,b)) dfs(a+1,b,c++,3);
			break;
		case 4:
			if(check(a+1,b-1)) dfs(a+1,b-1,c++,4);
			break;
		case 5:
			if(check(a,b-1)) dfs(a,b-1,c++,5);
			break;
		case 6:
			if(check(a-1,b-1)) dfs(a-1,b-1,c++,6);
			break;
		case 7:
			if(check(a-1,b)) dfs(a-1,b,c++,7);
			break;
		case 8:
			if(check(a-1,b+1)) dfs(a-1,b+1,c++,8);
			break;
	}
	//cout << "Á¾·á"<< endl;
	
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
	
		for(m=0;m<N*N;m++){
			for(i=0;i<N;i++){
				for(j=0;j<N;j++){
					ttry++;
					if(ttry<=m) continue;
//					cout<< arr[i][j].location << "! ";
					if(check2(arr[i][j].location)&&arr[i][j].value==0){ // Äý »ý¼º½Ã 
						cnt=0;
						Qcnt++;
						printf("Äý%d: %d \n",Qcnt, arr[i][j].location);
						buf[bufI]=arr[i][j].location;
						bufI++;
						dfs(i,j,cnt,0);
						for(int ii=0;ii<N;ii++){
		for(int jj=0;jj<N;jj++){
			printf("%d ",arr[ii][jj].value);
		}
		cout<< endl;
	}cout<< endl;
					}
				}
			}
				cout << endl;
				
			if(Qcnt==N){
				for(k=0;k<N;k++){
					Tbuf[TbufI]=buf[k];
					TbufI++;
				}
			}
			resett();
			ttry=0;
		}
	
	printf("%d ",(TbufI)/N);
	return 0;
}


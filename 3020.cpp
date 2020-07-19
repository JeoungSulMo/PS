#include<stdio.h>
#include<algorithm>
using namespace std;
// true : 아래에서 위로 
// 배열을 참조하는 속도 일반 연산한번 하는속도 차이는? 
int N,H,i,j;
int arr1[500001];
int arr2[500001];
int ans[500001];

int main(){
	scanf("%d %d",&N,&H);
	int h1,h2;
	for(i=0;i<N/2;i++){
		scanf("%d %d",&h1,&h2);
		arr1[h1]+=1;
		arr2[h2]+=1;
	}
	
	for(i=H;i>0;i--)arr1[i-1]+=arr1[i];
	for(i=H;i>0;i--)arr2[i-1]+=arr2[i];
	for(i=0;i<H;i++) ans[i]=arr1[i+1]+arr2[H-i];
	
	sort(ans,ans+H);
	int count=0,k=0;
	while(ans[k]==ans[0]) {
		if(ans[k]==ans[0])count++;
		k++;	
	}
	printf("%d %d",ans[0],count);
	
	return 0;
}

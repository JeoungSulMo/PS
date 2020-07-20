#include <string>
#include <vector>
#include <iostream>

using namespace std;

int d[32005];

int dp(int a, int k){
	if(a==k) return d[k]=1;
	if(k==1) return d[k]=2;
	if(k==2) return d[k]=3;	
}

int solution(int N, int number) {
  int answer = 0;
  dp(N,number);
  
  return answer;
}

int main(){
	cout << solution(5,12);
	return 0;
}

#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>

using namespace std;
typedef struct mon{
	string name;
	int num;
}mon;
mon arrN[100005]
string arrM[100005];
int N,M,i,j,s,e,mid;
string question;

bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for(i=0;i<N;i++) cin >> arrN1[i],arrN2[i]=arrN1[i];
	sort<string>(arrN, arrN+N);
	for(i=0;i<M;i++){
		cin >> question;
		if(check_number(question)){
			
		}else{
	
		}
	}
	for(i=0; i<M;i++) cout<<arrM[i]<< '\n';
	
	return 0;
}

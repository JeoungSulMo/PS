#include <iostream>
#include <algorithm>
using namespace std;

int a,b,v,cur,day;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a>>',' >> b >> v;
	day=(v-a)/(a-b);
	cur = day*(a-b);
	while(cur<v){
		cur+=a;
		day+=1;
		if(cur>=v) break;
		cur-=b;
	}
	cout << day;
	
	
	return 0;
}

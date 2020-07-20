#include <string>
#include <vector>
#include <iostream>
#define PLUS 1
#define MINUS 0
#define START_INDEX 0
using namespace std;
int numbers_size, buf;
void dfs(int indx, int sign,int cur, vector<int> arr,int* target,int* answer);

int solution(vector<int> numbers, int target) {
    int answer = 0;
    numbers_size=numbers.size();
    dfs(START_INDEX,PLUS,0,numbers,&target,&answer);
    dfs(START_INDEX,MINUS,0,numbers,&target,&answer);
    return answer;
}
int main(){
	vector<int> testcase;
	for(int i=0;i<5;i++) testcase.push_back(1);
	cout << solution(testcase,3);
	return 0;
}

void dfs(int indx, int sign,int cur, vector<int> arr, int* target, int* answer){
    if(sign) cur+=arr[indx];
    else cur-=arr[indx];
    if(indx==numbers_size-1) {
        if(cur == *target) *answer+=1;
        cout << cur << " answer : "<< *answer << endl;
        return;
    }
    dfs(indx+1, PLUS, cur, arr, target, answer);
    dfs(indx+1, MINUS, cur, arr, target, answer);
}

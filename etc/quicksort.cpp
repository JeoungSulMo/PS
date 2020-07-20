#include<iostream>
#include<vector>

using namespace std;

vector<int> swapp(vector<int> arr, int a, int b){
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
	return arr;
}

vector<int> sorting(vector<int> arr, int s,int e){
	int pivot=(s+e)/2;
	int bs=s,be=e;
	while(bs!=be){
		while(arr[bs]<arr[pivot]&&s!=pivot)bs++;
		while(arr[pivot]<arr[be]&&e!=pivot)be--;
		if(bs==be) break;
		cout << bs << " " << be << "\n";
		arr=swapp(arr,bs,be);
	}
	cout << endl;
	for(int i=0;i<9;i++)
		cout << arr[i] << " ";
	cout << endl;
	if(pivot!=s)arr=sorting(arr,s,pivot);
	if(pivot+1!=e)arr=sorting(arr,pivot,e);
	return arr;
}
vector<int> qsort(vector<int> arr){
	int s=0;
	int e=arr.size()-1;
	return sorting(arr,s,e);
};

int main(){
	vector<int> a = {1,9,3,4,8,5,6,2,7};
	a=qsort(a);
	for(int i=0;i<a.size();i++)
		cout << a[i] << " ";
	return 0;
}

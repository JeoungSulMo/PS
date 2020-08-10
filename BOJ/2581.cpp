#include <iostream>

using namespace std;

int n, m;
int arr[1000005];
void fun(int a)
{
    for (int i = 2; i <= a; i++)
    {
        if (arr[i] == 0) {
            int k = i;
            arr[k]=1;
            k+=i;
            while (k<=1000000) {
                arr[k]=-1;
                k+=i;
            }
        }

    }
}
void _print(int a, int b) {
    for (int i=a;i<=b;i++)
        if (arr[i]==1)
            cout << i << '\n';
}
int main()
{
    cin >> n >> m;
    fun(m);
    _print(n, m);
    return 0;
}
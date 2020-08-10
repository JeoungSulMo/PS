#include <iostream>

using namespace std;

int n;
int arr[105];
int total = 0;
void dp(int a)
{
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
            return;
    }
    total++;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            continue;
        dp(arr[i]);
    }
    cout << total;
    return 0;
}
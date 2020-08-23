#include <iostream>

using namespace std;

int n, mmax;
float arr[1005], total;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (mmax<arr[i]) mmax=arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        total+=arr[i]/(float)mmax*100;
    }
    cout << total/(float)n;
    return 0;
}
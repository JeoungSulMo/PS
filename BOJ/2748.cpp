#include <iostream>

using namespace std;
typedef long long ll;
int n;
ll arr[100];
ll func(int a)
{
    if (arr[a])
        return arr[a];
    if (a == 0)
        return 0;
    else if (a == 1)
        return 1;
    else
        return arr[a] = func(a - 1) + func(a - 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cout << func(n);
    return 0;
}
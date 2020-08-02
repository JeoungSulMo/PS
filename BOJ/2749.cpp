#include <iostream>

using namespace std;
typedef long long ll;
ll n;
ll arr[1500005];
void func()
{
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 0; i < 1500000; i++)
    {
        arr[i + 2] = (arr[i + 1] + arr[i]) % 1000000;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    func();
    cout << arr[n % 1500000];
    return 0;
}
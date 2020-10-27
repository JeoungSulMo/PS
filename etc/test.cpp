#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, less<int> > q;     // 최대힙
    priority_queue<int, vector<int>, greater<int> > q1; // 최소힙
    q.top();                                           // 루트가되는 노드
    q.push(3);                                         // 큐에 추가
    q.push(1);                                         // 큐에 추가
    q.push(7);                                         // 큐에 추가
    q1.push(3);
    q1.push(1);
    q1.push(7);
    while (!q.empty())
    {
        cout << q.top() << " " << q1.top()<< endl;
        q.pop(); // 루트노드 제거
        q1.pop();
    }
    return 0;
}
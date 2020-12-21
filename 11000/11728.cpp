#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;
	int N, M; cin >> N >> M;

	for (int i = 0; i < N + M; i++)
	{
		int x; cin >> x;
		pq.push(x);
	}
	while(!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}

	return 0;
}
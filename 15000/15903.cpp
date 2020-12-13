#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	
	priority_queue<long long,vector<long long>,greater<long long>> pq;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		pq.push(x);
	}
	for (int i = 0; i < m; i++)
	{
		long long temp = pq.top();
		pq.pop();
		temp += pq.top(); 
		pq.pop();

		pq.push(temp); pq.push(temp);
	}
	long long sum = 0;
	while(!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}

	cout << sum;

	return 0;
}
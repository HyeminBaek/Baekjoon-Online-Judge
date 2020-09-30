#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;
	queue<int> q;
	vector<int> v;
	for (int i = 1; i <= N; i++)
		q.push(i);

	int cnt = 0;
	while (!q.empty())
	{
		cnt++;
		if (cnt == K)
		{
			v.push_back(q.front());
			q.pop();
			cnt = 0;
		}
		else
		{
			q.push(q.front());
			q.pop();
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (i == 0)
			cout << "<";
		if (i < v.size() - 1)
			cout << v[i] << ", ";
		else
			cout << v[i] << ">";
	}
	
	return 0;
}
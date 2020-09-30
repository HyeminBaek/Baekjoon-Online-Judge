#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;
	
	queue<int> q;
	queue<int> answer;
	for (int i = 1; i <= N; i++)
		q.push(i);

	int cnt = 0;
	while (!q.empty())
	{
		cnt++;
		if (cnt == K)
		{
			answer.push(q.front());
			q.pop();
			cnt = 0;
		}
		else
		{
			q.push(q.front()); q.pop();
		}
	}
	while(!answer.empty())
	{
		if (answer.size()==N)
			cout << "<";
		if (answer.size() > 1)
		{
			cout << answer.front() << ", ";
			answer.pop();
		}
		else
		{
			cout << answer.front() << ">";
			answer.pop();
		}
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
1. ����ǰ�� ���� ���� �ؼ� X�� ����� �� Y�� �ʿ��ϸ� X->Y�� ���� ����
2. ���� ������ ���� ���� ������� �湮�Ͽ� ��ǰ ����
3. n�� ��ǰ�� �ʿ��� ��ǰ ���� = ������ǰ * K+ �Ǵٸ� ������ǰ*k
*/

struct components
{
	int num, cnt;
};
int N;
vector<components> v[101];
bool base[101];
int indegree[101];
int answer[101];

void toplogical()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);	answer[i] = 1;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		int cur = q.front();
		q.pop();

		for (components next : v[cur])
		{
			answer[next.num] += answer[cur] * next.cnt;
			if (--indegree[next.num] == 0) q.push(next.num);
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> N >> T;
	for (T; T > 0; T--)
	{
		int X, Y, K; cin >> X >> Y >> K;

		v[X].push_back({ Y,K });
		indegree[Y]++; base[X] = true;
	}
}
void print()
{
	for (int i = 1; i <= N; i++)
	{
		if(!base[i])
			cout << i << " " << answer[i] << "\n";
	}
}
int main()
{
	init();
	toplogical();
	print();

	return 0;
}
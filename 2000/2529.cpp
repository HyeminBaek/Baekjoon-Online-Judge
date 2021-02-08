#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <functional>
using namespace std;

/*
���� ������ �ʿ��� ���� �׷������� �ݵ�� �ڽź��� ����Ǿ�� �� ����
�������� �۾��� �� �� �ִ� ���

�� �ε�ȣ ���ڸ��� �����Ǿ�� ���ڸ��� ���� ����

1. �׸����ϰ� �ִ��� 9���� 9-K����, �ּҴ� 0���� K���� ����
2. �Է����� ���� �ε�ȣ�� ������Ű�� -> �ƴϸ� <- �������� �׷����� ����
3. �̸� ���������� ����� ����
*/
int k;
char arr[9];
vector<int> MAX[10], MIN[10];
int MAXin[10], MINin[10];

pair<string, string> toplogical()
{
	priority_queue<int> q; //�߿� �� pq�� �ؾ� ��
	for (int i = 9; i >= 9 - k; i--)
	{
		if (MAXin[i] == 0)
			q.push(i);
	}
	string max = "", min = "";
	for (int i = 9; i >= 9 - k; i--)
	{
		int cur = q.top();
		q.pop();
		max += to_string(cur);

		for (int next : MAX[cur]) //����
			if (--MAXin[next] == 0) q.push(next);
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i <= k; i++)
	{
		if (MINin[i] == 0)
			pq.push(i);
	}
	for (int i = 0; i <= k; i++)
	{
		int cur = pq.top();
		pq.pop();
		min += to_string(cur);

		for (int next : MIN[cur])
			if (--MINin[next] == 0) pq.push(next);
	}
	return { max,min };
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;

	int maxIdx = 9, minIdx = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];

		if (arr[i] == '<')
		{
			MAX[maxIdx - 1].push_back(maxIdx);
			MAXin[maxIdx--]++;

			MIN[minIdx].push_back(minIdx + 1);
			MINin[++minIdx]++;
		}
		else
		{
			MAX[maxIdx].push_back(maxIdx - 1);
			MAXin[--maxIdx]++;

			MIN[minIdx + 1].push_back(minIdx);
			MINin[minIdx++]++;
		}
	}
}
int main()
{
	init();
	pair<string, string> answer = toplogical();

	cout << answer.first << "\n" << answer.second;

	return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <functional>
using namespace std;

map<int, int> m;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq, sg; //����,�� ��,num

void sol()
{
	int cur = 1; //���ݱ��� ��ǻ�Ͱ� �� �� �ʿ��ߴ���

	sg.push({ pq.top().second,cur });
	pq.pop(); m.insert({ cur++, 1 });

	priority_queue<int, vector<int>, greater<int>> com; //�� �ڸ� ��

	while (!pq.empty())
	{
		int st = pq.top().first, ed = pq.top().second;
		pq.pop();

		while (!sg.empty()) //���� ����� �� �ڸ� pq�� �ִ´�
		{
			int edt = sg.top().first, num = sg.top().second;

			if (edt <= st)
			{
				com.push(sg.top().second);
				sg.pop();
			}
			else break;
		}

		if (com.empty()) //�� �ڸ��� ������
		{
			sg.push({ ed,cur }); //�� ��ǻ�� �߰�
			m.insert({ cur++, 1 });
		}
		else //������
		{
			sg.push({ ed,com.top() }); //�� �ڸ��� ��� �߰�
			m[com.top()]++; //�󵵼� ����
			com.pop(); 
		}
	}
	cout << cur - 1 << "\n";

	for (int i = 1; i < cur; i++)
		cout << m[i] << " ";
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (N; N > 0; N--)
	{
		int P, Q; cin >> P >> Q;
		pq.push({ P,Q });
	}
}
int main()
{
	init();
	sol();

	return 0;
}

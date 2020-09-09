#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;

	int arr[101] = { 0, }; int m[101] = { 0, };

	vector<int> q;
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		m[arr[i]]++;
	}

	int answer = 0;
	for (int i = 0; i < K; i++)
	{
		bool plug = false;
		for (int j = 0; j < q.size(); j++)
		{
			if (q[j] == arr[i])
			{
				plug = true; break;
			}
		}
		if (q.size() < N)
		{
			if (!plug)
			{
				q.push_back(arr[i]);	m[arr[i]]--;
			}
			else
			{
				for (int j = 0; j < q.size(); j++)
				{
					if (q[j] == arr[i])
					{
						m[q[j]]--; break;
					}
				}
			}
		}
		else //��Ƽ���� �� á�� ��
		{
			if (!plug) //�÷��װ� ��Ƽ�ǿ� �� �������� ��
			{
				bool flag = false;
				for (int j = 0; j < q.size(); j++) //������ �ȳ����� �÷��װ� �������� ��
				{
					if (m[q[j]] == 0)
					{
						answer++;//�÷��׸� ����
						--m[arr[i]];
						q[j] = arr[i];
						flag = true; break; //���� �����Ǿ����� �ǹ�
					}
				}
				if (!flag) //������ �ȳ����� �÷��װ� ���� ��
				{
					//���� ���ʰ� ���� �ʴ� �÷��׸� �̴´�
					int idx = -1, val= - 1;
					for (int l = 0; l < q.size(); l++)//���� ���ʰ� �ʴ� �÷��� ã��
					{
						for (int j = i + 1; j < K; j++)
						{
							if (arr[j] == q[l])
							{
								if (j > idx)
								{
									idx = j; val = l;
								}
								break;
							}
						}
					}
					--m[arr[i]];
					q[val] = arr[i];
					answer++;
				}
			}
			else
			{
				for (int j = 0; j < q.size(); j++)
				{
					if (q[j] == arr[i])
					{
						m[q[j]]--; break;
					}
				}
			}
		}
	}
	cout << answer;

	return 0;
}
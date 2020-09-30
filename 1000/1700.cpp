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
		else //멀티탭이 꽉 찼을 때
		{
			if (!plug) //플러그가 멀티탭에 안 꽂혀있을 때
			{
				bool flag = false;
				for (int j = 0; j < q.size(); j++) //앞으로 안나오는 플러그가 꽂혀있을 때
				{
					if (m[q[j]] == 0)
					{
						answer++;//플러그를 뽑음
						--m[arr[i]];
						q[j] = arr[i];
						flag = true; break; //값이 변동되었음을 의미
					}
				}
				if (!flag) //앞으로 안나오는 플러그가 없을 때
				{
					//다음 차례가 제일 늦는 플러그를 뽑는다
					int idx = -1, val= - 1;
					for (int l = 0; l < q.size(); l++)//다음 차례가 늦는 플러그 찾기
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
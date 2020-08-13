#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, R; cin >> N >> R;
	vector<pair<int, pair<int, int>>> frame; //추천 수,최근,학생 num
	bool visited[101];
	memset(visited, false, sizeof(visited));

	int pointer = 0;

	for (int i = 0; i < R; i++)
	{
		int student; cin >> student;

		if (!visited[student]) //아직 한번도 호명되지 않은 경우
		{
			if (pointer < N)//사진틀이 빈 경우
			{
				frame.push_back({ 1,{ i,student } });
				visited[student] = true;
				pointer++;
			}
			else
			{
				sort(frame.begin(), frame.end());
				swap(frame.front(), frame.back());
				visited[frame.back().second.second] = false;
				frame.pop_back();
				frame.push_back({ 1,{ i,student } });
				visited[student] = true;
			}
		}
		else //호명된 경우
		{
			for (int j = 0; j < frame.size(); j++)
			{
				if (frame[j].second.second == student)
				{
					frame[j].first++; break;
				}
			}
		}
	}
	for (int i = 1; i < 101; i++)
	{
		if (visited[i])
			cout << i << " ";
	}

	return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int arr[10];
	for (int i = 0; i < 10; i++)
		arr[i] = 1;
	int answer = 1;

	string s; cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		int idx = s[i] - '0';
		if (arr[idx] > 0)
		{
			arr[idx]--;
		}
		else
		{
			if (idx == 6 && arr[9] > 0)
			{
				arr[9]--;
			}
			else if (idx == 9 && arr[6] > 0)
				arr[6]--;
			else
			{
				answer++;
				for (int j = 0; j < 10; j++)
				{
					arr[j]++;
				}
				arr[idx]--;
			}
		}
	}
	cout << answer;

	return 0;
}

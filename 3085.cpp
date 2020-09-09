#include <iostream>
#include <algorithm>
using namespace std;

int N; char arr[50][50];
int cnt()
{
	int rtn = 0;
	//가로로 확인
	for (int i = 0; i < N; i++)
	{
		int len = 1;
		for (int j = 0; j < N - 1; j++)
		{
			if (arr[i][j] == arr[i][j + 1])
				len++;
			else
			{
				rtn = max(rtn, len);
				len = 1;
			}
		}
		rtn = max(rtn, len);
	}
	//세로로 확인
	for (int i = 0; i < N; i++)
	{
		int len = 1;
		for (int j = 0; j < N - 1; j++)
		{
			if (arr[j][i] == arr[j + 1][i])
				len++;
			else
			{
				rtn = max(rtn, len);
				len = 1;
			}
		}
		rtn = max(rtn, len);
	}
	return rtn;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (arr[i][j] != arr[i][j + 1])
			{
				char temp = arr[i][j];
				arr[i][j] = arr[i][j + 1];
				arr[i][j + 1] = temp;

				answer = max(answer, cnt());

				temp = arr[i][j];
				arr[i][j] = arr[i][j + 1];
				arr[i][j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (arr[j][i] != arr[j + 1][i])
			{
				char temp = arr[j][i];
				arr[j][i] = arr[j + 1][i];
				arr[j + 1][i] = temp;

				answer = max(answer, cnt());

				temp = arr[j][i];
				arr[j][i] = arr[j + 1][i];
				arr[j + 1][i] = temp;
			}
		}
	}

	cout << answer;

	return 0;
}
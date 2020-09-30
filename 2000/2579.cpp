#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;   cin >> N;
	int dp[301][2]; bool flag = false;

	int* stair = new int[N + 1];
	for (int i = 1; i < N + 1; i++)
		cin >> stair[i];

	//��� �������� ����- 1, �ƴ�- 0
	dp[0][0] = 0, dp[0][1] = 0, dp[1][0] = stair[1];
	for (int i = 2; i <= N; i++)
	{
		//�������� ��� ���: ���� ��ܿ��� �������� ���� �ʾҾ�� ��
		dp[i][1] = dp[i - 1][0] + stair[i];
		//�������� ���� �ʴ� ���
		dp[i][0] = max(dp[i - 2][1], dp[i - 2][0]) + stair[i];
	}
	cout << max(dp[N][0], dp[N][1]);

	return 0;
}
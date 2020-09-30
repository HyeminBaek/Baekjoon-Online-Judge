#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int dp[101][100001] = { 0, }; //dp[������ i�� ��][������ �� ���� �� �ִ� �뷮]
	int w[101];	int vl[101];

	int N, K, result = 0;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> w[i] >> vl[i];

	for (int i = 1; i <= N; i++) //i��° ������ ���濡 ������ ���θ� ���� ��ü for��
	{
		for (int j = K; j >= 0; j--)
		{
			if (w[i] <= j) //�� ���� �� �ִ� ���Ժ��� ������Ƿ� ���濡 ���� �� ����
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + vl[i]);
				result = max(result,dp[i][j]);
			}
			else //�޸������̼ǿ�
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << result;

	return 0;
}
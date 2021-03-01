#include <iostream>
#include <algorithm>
using namespace std;

/*
sol 1) �� ���� ���� 2�ʳ� �ֱ淡 2��for �� �����鼭 �ϳ��� �����ϸ鼭 DP �迭�� ���� -> TLE
sol 2) 
�ð����⵵ �ڴʰ� ��� �� for�� �� ������ ������ ���� ������, 2���� dp ����
2���� dp ���� �ִ´�/���� �� �� �ϳ��� ����
���� ���������� �� ������ ������ ���� �ȳ��� �� ������ �ؼ��� ��

dp[n][2] => 0�̸� �� �� ��, 1�̸� i��°�� ���� ������ ��
dp[n][0]�� ��� ������ �״�� �� ����
dp[n][1]�� ��� �� ���ΰ� �� ���ΰ��� �����ؾ� ��
=> dp[i-1][0] �� ��찡 ū ��� / dp[i-1][1]+arr[i] �̹� �տ��� ���� �Ϳ��ٰ� ����
*/

void init(int&,int []);
int sol(const int,int []);

int main()
{
	int N;
	int arr[100001];

	init(N,arr);
	cout << sol(N, arr);

	return 0;
}
int sol(const int N, int arr[])
{
	int answer = arr[0];
	
	int dp[100001][2];
	dp[0][0] = arr[0], dp[0][1] = 0;

	for (int i = 1; i < N; i++)
	{
		dp[i][0] = arr[i], dp[i][1] = dp[i - 1][0];

		if (dp[i - 1][0] + arr[i] > dp[i][0]) dp[i][0] = arr[i] + dp[i - 1][0];
		if (dp[i - 1][1] + arr[i] > dp[i][1]) dp[i][1] = arr[i] + dp[i - 1][1];

		answer = (answer < dp[i][0]) ? dp[i][0] : answer;
		answer = (answer < dp[i][1]) ? dp[i][1] : answer;
	}

	return answer;
}
void init(int &N,int arr[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
}
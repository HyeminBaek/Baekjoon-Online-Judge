#include <iostream>
using namespace std;

int N, M;
int arr[10000],sum[10000];

int twopointer()
{
	int low = 0, high = N - 1, answer = 0;

	while (low <= high) //N�� 1�� �� ���� �����Ƿ� ��ȣ�� �ٿ��� ��
	{
		if (arr[high] + sum[high] - sum[low] == M) answer++;

		if (low == high)
		{
			low++; high = N - 1;
		}
		else
			high--;
	}

	return answer;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sum[1] = arr[0];
	for (int i = 2; i < N; i++)
		sum[i] = sum[i - 1] + arr[i - 1];
}
int main()
{
	init();
	cout << twopointer();

	return 0;
}
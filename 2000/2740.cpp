#include <iostream>
using namespace std;

int N, M, K;
int A[100][100], B[100][100];

void solution()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int temp = 0;
			for (int k = 0; k < M; k++)
			{
				temp += A[i][k] * B[k][j];
			}
			cout << temp << " ";
		}
		cout << "\n";
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	}

	cin >> M >> K;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
			cin >> B[i][j];
	}
}
int main()
{
	init();
	solution();

	return 0;
}
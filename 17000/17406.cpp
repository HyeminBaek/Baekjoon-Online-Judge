#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int SIZE = 51;

struct operation
{
	int r;	int c;	int s;
};

int add(const int N, const int M, int arr[][SIZE])
{
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= M; j++)
			sum += arr[i][j];

		if (answer == 0 || answer > sum)
			answer = sum;
	}

	return answer;
}
void spin(const int r, const int c,const int S, int arr[][SIZE])
{
	for (int s = 1; s <= S; s++)
	{
		int temp = arr[r - s][c + s]; //A[2][5]
		for (int i = c + s; i > c - s; i--)//�� ����
		{
			arr[r - s][i] = arr[r - s][i - 1]; //A[2][5]�� A[2][4]�� ����
		}
		int temp1 = arr[r + s][c + s];//A[4][5]
		for (int i = r + s; i > r - s; i--)//������ ����
		{
			arr[i][c + s] = arr[i - 1][c + s];//A[4][5]�� A[3][5]�� ����
		}
		arr[r - s + 1][c + s] = temp; //A[3][5]�� A[2][5]����
		temp = arr[r + s][c - s]; //A[4][3]
		for (int i = c - s; i < c + s; i++)
		{
			arr[r + s][i] = arr[r + s][i + 1];//A[4][3]�� A[4][4]����
		}
		arr[r + s][c + s - 1] = temp1; //A[4][4]�� A[4][5] ����

		for (int i = r - s; i < r + s; i++)
		{
			arr[i][c - s] = arr[i + 1][c - s];//A[2][3]�� A[3][3] ����
		}
		arr[r + s - 1][c - s] = temp;
	}
}
void init(int& N, int& M,int& K, int arr[][SIZE]) //�ʱ�ȭ �Լ�
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
}
int main()
{
	int N, M, K;
	int arr[SIZE][SIZE];
	init(N, M, K, arr);

	vector<operation> v;
	for (int i = 0; i < K; i++)
	{
		operation o;
		cin >> o.r >> o.c >> o.s;
		v.push_back(o);
	}

	vector<int> p(K);
	for (int i = 0; i < K; i++)
		p[i] = i;

	int answer = -1;
	int copy[SIZE][SIZE];
	do { //���������
		memcpy(copy, arr, sizeof(arr));
		for (int i = 0; i < p.size(); i++)
		{
			operation o; o = v[p[i]];
			spin(o.r, o.c, o.s, arr);
		}
		int result = add(N, M, arr);
		if (answer == -1 || answer > result) answer = result;
		memcpy(arr, copy, sizeof(copy));
	} while (next_permutation(p.begin(), p.end()));

	cout << answer;

	return 0;
}
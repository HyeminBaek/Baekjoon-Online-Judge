#include <iostream>
using namespace std;

int N, S, answer;
int arr[20];

void com(int idx, int sum)
{
	if (idx == N)
	{
		if (sum == S) answer++;
		return;
	}
	com(idx + 1, sum + arr[idx]);
	com(idx + 1, sum);
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}
int main()
{
	init();
	com(0, 0);
	if (S == 0) answer -= 1;
	cout << answer;

	return 0;
}
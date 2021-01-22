#include <iostream>
#include <cmath>
using namespace std;

bool isPrime[246913];
int sum(int n)
{
	int answer = 0;
	for (int i = n + 1; i <= 2 * n; i++)
	{
		if (isPrime[i]) answer++;
	}
	return answer;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i = 2;i<=246912;i++)
		isPrime[i] = true;
	for (int i = 2; i <= 246912; i++)
	{
		if (isPrime[i]) {
			for (int j = i * 2; j <=246912 ; j += i)
				isPrime[j] = false;
		}
	}
	while (1)
	{
		int n; cin >> n;
		if (n == 0) break;

		cout << sum(n) << "\n";
	}
	return 0;
}
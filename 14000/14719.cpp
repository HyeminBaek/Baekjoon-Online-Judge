#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int W, H; cin >> W >> H;
	int arr[500];
	for (int i = 1; i <= H; i++)
		cin >> arr[i];

	int answer = 0;

	int right = 0, left = 0;
	for (int i = 1; i < H; i++)
	{
		right = 0;

		left = (arr[i] > left) ? arr[i] : left;

		for (int j = i + 1; j <= H; j++)
			right = (arr[j] > right) ? arr[j] : right;

		int tmp = (right < left) ? right : left;
		int dif = tmp - arr[i];

		if (dif > 0) answer += dif;
	}

	cout << answer;

	return 0;
}
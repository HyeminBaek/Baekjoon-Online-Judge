#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	long long* tree = new long long[n];
	for (int i = 0; i < n; i++)
		cin >> tree[i];

	sort(tree, tree + n);

	long long low = 1LL;
	long long high = tree[n - 1];
	long long mid = (low + high) / 2;
	long long left = 0;
	long long answer = 0;

	while (low <= high)
	{
		left = 0;
		mid = (low + high) / 2; //mid를 조건을 만족시키는 값의 최댓값으로 설정
		for (int i = 0; i < n; i++)
		{
			if (tree[i] - mid > 0)
				left += tree[i] - mid;
		}
		//cout << low << " " << mid << " " << high << " " << left << endl;
		
		if (left >= m) //"적어도"이기 때문에 답은 m 이상이 될 것
		{
			if (answer < mid)//답을 만족시키는 mid 값 중 최댓값을 저장
				answer = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	
	cout << answer;

	return 0;
}
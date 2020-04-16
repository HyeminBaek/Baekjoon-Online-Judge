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
		mid = (low + high) / 2; //mid�� ������ ������Ű�� ���� �ִ����� ����
		for (int i = 0; i < n; i++)
		{
			if (tree[i] - mid > 0)
				left += tree[i] - mid;
		}
		//cout << low << " " << mid << " " << high << " " << left << endl;
		
		if (left >= m) //"���"�̱� ������ ���� m �̻��� �� ��
		{
			if (answer < mid)//���� ������Ű�� mid �� �� �ִ��� ����
				answer = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	
	cout << answer;

	return 0;
}
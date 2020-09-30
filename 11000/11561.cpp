#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		unsigned long long n;
		cin >> n;

		unsigned long long low = 1;
		unsigned long long high = n;
		unsigned long long mid = (low + high) / 2;

		while (low <= high)
		{
			mid = (low + high) / 2;
			
			//계차 수열 항을 돌다가 n까지의 거리가 전에 움직인 거리보다 짧으면 루프를 나감
			if (n - ((mid*(mid + 1)) / 2) <= mid)
				break;
			else
			{
				//계차 수열의 일반항을 구하고, 구하려는 값 mid를 (일반항 연산 결과) <= n 을
				//만족하는 값 중 가장 큰 수로 두었다.
				if ((mid*(mid + 1)) / 2 <= n)
					low = mid + 1;
				else
					high = mid - 1;
			}
			//변수 값 변화 측정용
			//cout << low << " " << mid << " " << high << " " << (mid*mid + mid) / 2 << endl;
		}

		cout << mid << "\n";
	}

	return 0;
}
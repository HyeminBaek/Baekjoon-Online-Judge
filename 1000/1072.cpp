#include <iostream>
using namespace std;

int main()
{
	long long x, y;
	cin >> x >> y;

	int z = 100*y / x;

	if (z >= 99)
	{
		cout << "-1";
		return 0;
	}

	long long low = 1;
	long long high = x;
	long long mid=0;
	int temp = 100*(y + mid) / (x + mid);

	while (low <= high)
	{
		mid = (low + high) / 2;
		temp = 100*(y + mid) / (x + mid);

		if (temp > z)
			high = mid - 1;
		else
			low = mid + 1;
	
		//cout << low << " " <<mid<<" "<< high << " " << temp << endl;
		//cout << x + mid << " " << y + mid << endl;
	}

	cout << low;

	return 0;
}
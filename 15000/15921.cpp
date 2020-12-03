#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
	int N; cin >> N;

	if (N == 0)
	{
		cout << "divide by zero";
		return 0;
	}

	int* arr = new int[N];
	double avg = 0, exp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i]; avg += arr[i];
	}
	avg /= (double)(N);

	sort(arr, arr + N);

	int num = 1;
	for (int i = 1; i < N ; i++)
	{
		if (arr[i - 1] != arr[i])
		{
			exp += arr[i - 1] * (num / (double)(N));
			num = 1;
		}
		else
			num++;
	}
	exp += arr[N - 1] * (num / (double)(N));

	//cout << avg << " " << exp << endl;
	if (exp == 0)
		cout << "divide by zero";
	else
		cout << fixed<<setprecision(2) << avg / exp;

	return 0;
}
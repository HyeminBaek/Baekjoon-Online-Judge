#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int arr[8001] = { 0 };
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		arr[v[i] + 4000]++;
	}

	sort(v.begin(), v.end());

	double avg = 0;
	for (int i = 0; i < n; i++)
		avg += v[i];
	avg /= n;
	int num = 0;
	if (avg >= 0)
		num = avg + 0.5;
	else
		num = avg - 0.5;

	vector<int> temp;
	int max = arr[0];
	for (int i = 1; i < 8001; i++)
		if (arr[i] > max)
			max = arr[i];

	for (int i = 0; i < 8001; i++)
		if (arr[i] == max)
			temp.push_back(i);

	sort(temp.begin(), temp.end());

	cout << num << "\n" << v[n / 2] << "\n";
	if (temp.size() == 1)
		cout << temp[0] - 4000;
	else
		cout << temp[1] - 4000;

	cout << "\n" << v.back() - v.front();

	return 0;
}
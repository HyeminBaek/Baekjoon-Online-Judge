#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	int N; cin >> N;
	int* arr = new int[N];

	string s; cin >> s;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	vector<double> v;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 65 && s[i] < 91)
			v.push_back(arr[s[i] - 'A']);
		else
		{
			double temp = v.back();
			v.pop_back();

			if (s[i] == '+')
				temp += v.back();
			else if (s[i] == '-')
				temp = v.back() - temp;
			else if (s[i] == '/')
				temp = v.back() / temp;
			else if (s[i] == '*')
				temp *= v.back();

			v.pop_back();
			v.push_back(temp);
		}
	}
	cout << fixed << setprecision(2) << v.back();

	return 0;
}
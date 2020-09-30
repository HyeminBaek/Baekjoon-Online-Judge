#include <iostream>
#include <string>
using namespace std;

int main()
{
	string x;
	cin >> x;

	int sum = 0, num = 0;
	while (x.length() > 1)
	{
		for (int i = 0; i < x.length(); i++)
			sum += x[i] - '0';
		num++;
		x = to_string(sum);
		sum = 0;
	}

	cout << num << "\n";
	if (stoi(x) % 3 == 0)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
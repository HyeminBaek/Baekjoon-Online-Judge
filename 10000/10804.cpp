#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	for (int i = 1; i <= 20; i++)
		v.push_back(i);

	for (int i = 0; i < 10; i++)
	{
		int s, e; cin >> s >> e;

		s--; e--;
		vector<int> temp;
		for (int j = 0; j < s; j++)
			temp.push_back(v[j]);

		for (int j = e; j >= s; j--)
			temp.push_back(v[j]);

		for (int j = e + 1; j < 20; j++)
			temp.push_back(v[j]);

		v.clear();
		for (int j = 0; j < 20; j++)
			v.push_back(temp[j]);
	}
	for (int j = 0; j < 20; j++)
		cout << v[j] << " ";
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int scores[10];
	for (int i = 0; i < 10; i++)
		cin >> scores[i];

	vector<int> v; v.push_back(scores[0]);
	for (int i = 1; i < 10; i++)
	{
		v.push_back(scores[i] + v[i - 1]);
		if (v.back() > 100)
			break;
	}
	
	if (v.back() > 100)
	{
		if (v.back() - 100 <= 100 - v[v.size() - 2])
			cout << v.back();
		else 
			cout << v[v.size() - 2];
	}
	else
		cout << v.back();

	return 0;
}
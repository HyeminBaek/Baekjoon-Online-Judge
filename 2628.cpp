#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int w, h;
	cin >> w >> h;
	
	int t;
	cin >> t;

	vector<int> w_v;
	vector<int> h_v;
	w_v.push_back(0);
	h_v.push_back(0);
	w_v.push_back(h);
	h_v.push_back(w);
	for (int i = 0; i < t; i++)
	{
		int x, y;
		cin >> x >> y;
		switch (x)
		{
		case 0:
			w_v.push_back(y);
			break;
		case 1:
			h_v.push_back(y);
			break;
		}
	}
	sort(w_v.begin(), w_v.end());
	sort(h_v.begin(), h_v.end());

	//for (int i = 0; i < w_v.size(); i++)
	//	cout << w_v[i] << " ";
	//cout << endl;

	int w_max = 1, h_max = 1;
	for (int i = 1; i < w_v.size(); i++)
	{
		if (w_v[i] - w_v[i - 1] > w_max)
			w_max = w_v[i] - w_v[i - 1];
	}
	for (int i = 1; i < h_v.size(); i++)
	{
		if (h_v[i] - h_v[i - 1] > h_max)
			h_max = h_v[i] - h_v[i - 1];
	}
	cout << w_max * h_max;

	return 0;
}
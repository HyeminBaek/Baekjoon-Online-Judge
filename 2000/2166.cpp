#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

vector<pair<int, int>> v;

double cross(double x1, double y1, double x2, double y2)
{
	return (x1 * y2) - (x2 * y1);
}
double sol()
{
	double answer = 0;

	for (int i = 1; i < v.size() - 1; i++)
	{
		double x1 = (v[i].first - v[0].first), y1 = (v[i].second - v[0].second);
		double x2 = (v[i + 1].first - v[0].first), y2 = (v[i + 1].second - v[0].second);

		answer += cross(x1, y1, x2, y2) / 2.0;
	}

	return abs(answer);
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y; cin >> x >> y;
		v.push_back({ x,y });
	}
}
int main() {
	init();
	cout << fixed << setprecision(1) << sol();

	return 0;
}


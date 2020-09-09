#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; vector<int> v;
long long div_arr(int bg, int en)
{
	if (bg == en)
		return v[bg] * v[en];
	int mid = (bg+en) / 2, left = mid - 1, right = mid + 1;
	int minv = v[mid];	long long sum = v[mid], score = sum * minv;
	long long answer = max(div_arr(bg, mid), div_arr(mid + 1, en));
	while (bg <= left || right <= en)
	{
		if ((left >= bg && right <= en && v[right] > v[left]) || left < bg)
		{
			sum += v[right];
			if (minv > v[right])
				minv = v[right];
			right += 1;
		}
		else
		{
			if (left >= 0)
			{
				sum += v[left];
				if (minv > v[left])
					minv = v[left];
				left -= 1;
			}
		}
		score = max(score, sum * minv);
	}
	answer = max(answer, score);
	return answer;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}
}
int main()
{
	init();
	cout << div_arr(0, N - 1);

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
1. 처음 생각: 0을 기준으로 abs가 작은 순으로 나열 -> 왜냐하면 0에서 책을 들고 왔다갔다 해야하므로
하지만 답이 안 나옴, 앞구르기 뒷구르기 요래저래 생각해도 답이 안 나옴
그래서 결국 풀이를 봤는데 이해가 안 가는 점
-> 묶음으로 가는 건 이해하는데 왜 -37,-29에서 -29가 기준이 되는가?
abs 값은 -37이 더 큰데? 문제가 잘못 된건가?

2. 해설보고 난 후 생각: 한 번에 동시에 들 수 있는 갯수만큼 뭉텅이로 묶어서 처리
뭉텅이 중 max value*2(0으로 돌아가야 하므로), 그 값에서 마지막은 편도니까 이 부분 처리
*/
int M;
vector<int> v;
/* 1st try
struct compare 
{
	bool oper(int& f)
	{
		return abs(f) < cur;
	}
};

priority_queue<int, vector<int>, compare> pq;

void solution()
{
	int ans = 0;
	while (!pq.empty())
	{
		int prev = 0;
		for (int i = 0;i < M;i++)
		{
			if (pq.empty()) break;
			int cur = pq.top(); pq.pop();
			ans += abs(cur-prev);
			prev = cur;
		}
		if(!pq.empty()) ans += abs(prev);
	}

	cout << ans;
}
*/
void solution()
{
	int ans = 0, tmp = (abs(v[0]) > abs(v.back())) ? abs(v[0]) : abs(v.back());
	
	//plus or minus: if pm has false value, it means minus condition
	bool pm = (v[0] < 0) ? false : true;

	while (!v.empty())
	{
		int max = (!pm) ? abs(v[0]) : v.back();
		//cout << v[0] << endl;
		if (!pm && v[0] > 0)
		{
			pm = true; continue;
		}
		for (int i = 0;i < M;i++)
		{
			if (v.empty()) break;
			if (!pm && v[0] > 0) break;

			if (!pm) v.erase(v.begin());
			else v.pop_back();
		}
		
		ans += max * 2;
	}

	cout << ans - tmp;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N >> M;
	for (int i = 0;i < N;i++)
	{
		int x; cin >> x;
		v.push_back(x);
		//pq.push(x); 1st try
	}
	sort(v.begin(), v.end());
}
int main()
{
	init();
	solution();

	return 0;
}

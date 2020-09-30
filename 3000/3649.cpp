#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, n;
	while (cin >> x >> n) //여러개의 테스트케이스~~이므로 계속 입력을 받아야함
	{
		x *= 10000000; //센티미터를 나노미터로 변환
		vector<int> l;

		for (int i = 0; i < n; i++)
		{
			int length;
			cin >> length;
			l.push_back(length);
		}

		sort(l.begin(), l.end());
		bool tf = false;//조건을 만족하자마자 루프를 빠져나가도록. 시간초과 방지
		
		int low = 0; //인덱스로 이분탐색 수행할 것
		int high = l.size() - 1;
		int mid = 0;
		
		while (low < high) //n이 홀수인 경우 인덱스가 겹칠 수 있으므로 등호를 붙이지 않음
		{
			//cout << low << " " << high << endl;
			mid = l[low] + l[high];
			if (mid == x)
			{
				tf = true;
				cout << "yes " << l[low] << " " << l[high] << "\n";
				break;
			}
			//예제의 경우 1 2 99...98 99...99 순으로 정렬되는데 가장 작은 것의 짝은
			//중간이 아닌 맨끝에 위치할 확률이 높으므로 증감연산자로 접근
			if (mid < x)
				low++;
			else
				high--;
		}
		if (!tf) //한번도 true로 바뀌지 않았다는 것은 조건을 만족시키는 것이 없다는 것
			cout << "danger\n";
	}

	return 0;
}
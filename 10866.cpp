#include <iostream>
#include <string>
#include <vector>
using namespace std;

void rearrange(vector<int>& dq,string s)//연산 후 정렬을 위한 함수
{
	if (s == "push_front") //push의 경우 한 칸씩 뒤로 밀림
	{
		dq.push_back(dq.back());

		for (int i = dq.size() - 2; i > 0; i--)//앞에서 push해주었으므로 -2
			dq[i] = dq[i - 1];
	}
	if (s == "pop_front") //pop의 경우 한 칸씩 앞으로 당김
	{
		for (int i = 0; i < dq.size()-1; i++)
			dq[i] = dq[i + 1];
		dq.pop_back();
	}
}

int main()
{
	int n;
	cin >> n;//명령의 수를 입력받음

	vector<int> deque;//덱을 하나 생성

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		if (s == "push_front")
		{
			int x;
			cin >> x;

			if (deque.size() > 0)
			{
				rearrange(deque,s);
				deque[0] = x;
			}
			else
				deque.push_back(x);
		}
		if (s == "push_back")
		{
			int x;
			cin >> x;

			deque.push_back(x);
		}
		if (s == "pop_front")
		{
			if (deque.empty())
				cout << -1 << "\n";
			else
			{
				if (deque.size() == 1)
				{
					cout << deque[0] << "\n";
					deque.pop_back();
				}
				else
				{
					cout << deque[0] << "\n";
					rearrange(deque, s);
				}
			}
		}
		if (s == "pop_back")
		{
			if (deque.empty())
				cout << -1 << "\n";
			else
			{
				cout << deque.back() << "\n";
				deque.pop_back();
			}
		}
		if (s == "size")
		{
			cout << deque.size() << "\n";
		}
		if (s == "empty")
		{
			if (deque.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		if (s == "front")
		{
			if (deque.empty())
				cout << -1 << "\n";
			else
				cout << deque[0] << "\n";
		}
		if (s == "back")
		{
			if (deque.empty())
				cout << -1 << "\n";
			else
				cout << deque.back() << "\n";
		}

		//for (int i = 0; i < deque.size(); i++)
		//	cout << deque[i] << " ";
		//cout << endl;
	}

	return 0;
}
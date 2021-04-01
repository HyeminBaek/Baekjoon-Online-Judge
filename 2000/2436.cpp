#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

/*
1. �ִ����� �ּҰ������ �Է¹ް� �ּҰ������ �ִ������� ������
�� �ִ������� �� ���ԵǾ�� �ϹǷ� ����� �ʿ䰡 ����
2. ����� pair ���� ���μ��� ���� ���� 
3. 2�� �ִ������� ���Ѵ�
*/
int gcd;
priority_queue < pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;
int euclid(int a,int b)
{
	while (1)
	{
		if (a%b == 0)	return b;

		int temp = a % b;
		a = b;
		b = temp;
	}
}
void sol(int num)
{
	//�ִ������� 1
	for (int i = 1; i <= sqrt(num); i++)
	{
		if (num%i != 0) continue;
		if (euclid(num / i, i) == 1)
			pq.push({ (num / i * gcd) + (i*gcd),{i*gcd,num / i * gcd} });
	}
}
int init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int lcm;  cin >> gcd >> lcm;

	return lcm / gcd;
}
int main()
{
	int num = init();
	sol(num);
	cout << pq.top().second.first <<" "<< pq.top().second.second;

	return 0;
}
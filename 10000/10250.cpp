#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int h, w, n;
		cin >> h >> w >> n;

		int temp = 1;//ȣ���� ���� ���� ����
		while (n > h)
		{
			n -= h;//��� ���� tempȣ�� ������
			temp++;//���� ȣ�� ����� �����ϱ� ����
		}

		if (temp < 10)
			cout << n << "0" << temp << "\n";
		else
			cout << n << temp << "\n";
	}

	return 0;
}
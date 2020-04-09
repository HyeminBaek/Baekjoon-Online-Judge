#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		unsigned long long n;
		cin >> n;

		unsigned long long low = 1;
		unsigned long long high = n;
		unsigned long long mid = (low + high) / 2;

		while (low <= high)
		{
			mid = (low + high) / 2;
			
			//���� ���� ���� ���ٰ� n������ �Ÿ��� ���� ������ �Ÿ����� ª���� ������ ����
			if (n - ((mid*(mid + 1)) / 2) <= mid)
				break;
			else
			{
				//���� ������ �Ϲ����� ���ϰ�, ���Ϸ��� �� mid�� (�Ϲ��� ���� ���) <= n ��
				//�����ϴ� �� �� ���� ū ���� �ξ���.
				if ((mid*(mid + 1)) / 2 <= n)
					low = mid + 1;
				else
					high = mid - 1;
			}
			//���� �� ��ȭ ������
			//cout << low << " " << mid << " " << high << " " << (mid*mid + mid) / 2 << endl;
		}

		cout << mid << "\n";
	}

	return 0;
}
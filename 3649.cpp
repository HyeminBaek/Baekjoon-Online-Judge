#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, n;
	while (cin >> x >> n) //�������� �׽�Ʈ���̽�~~�̹Ƿ� ��� �Է��� �޾ƾ���
	{
		x *= 10000000; //��Ƽ���͸� ������ͷ� ��ȯ
		vector<int> l;

		for (int i = 0; i < n; i++)
		{
			int length;
			cin >> length;
			l.push_back(length);
		}

		sort(l.begin(), l.end());
		bool tf = false;//������ �������ڸ��� ������ ������������. �ð��ʰ� ����
		
		int low = 0; //�ε����� �̺�Ž�� ������ ��
		int high = l.size() - 1;
		int mid = 0;
		
		while (low < high) //n�� Ȧ���� ��� �ε����� ��ĥ �� �����Ƿ� ��ȣ�� ������ ����
		{
			//cout << low << " " << high << endl;
			mid = l[low] + l[high];
			if (mid == x)
			{
				tf = true;
				cout << "yes " << l[low] << " " << l[high] << "\n";
				break;
			}
			//������ ��� 1 2 99...98 99...99 ������ ���ĵǴµ� ���� ���� ���� ¦��
			//�߰��� �ƴ� �ǳ��� ��ġ�� Ȯ���� �����Ƿ� ���������ڷ� ����
			if (mid < x)
				low++;
			else
				high--;
		}
		if (!tf) //�ѹ��� true�� �ٲ��� �ʾҴٴ� ���� ������ ������Ű�� ���� ���ٴ� ��
			cout << "danger\n";
	}

	return 0;
}
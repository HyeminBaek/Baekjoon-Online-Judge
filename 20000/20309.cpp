#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	bool flag = true; //답을 체크하기 위한 플래그 변수
	for (int i = 0; i < N; i++)
	{
		if (arr[i] % 2 == 0)//짝수이면
		{
			if (i % 2 == 0)//인덱스 위치 1인 경우만 트리플 소트로 오름차순 정렬 가능
			{
				flag = false;
				break;
			}
		}
		else
		{
			if (i % 2 == 1)//인덱스 위치가 1인 경우 정렬 불가
			{
				flag = false;
				break;
			}
		}
	}

	if (flag)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;

	bool era[1001]; memset(era, true, sizeof(era));
	era[0] = false; era[1] = false;
	int idx = 0;


	for (int i = 2; i <= N; i++)
	{
		if (era[i])
		{
			for (int j = 1; i * j <= N; j++)
			{
				if (era[i*j])
				{
					idx++;
					//cout << i * j << endl;
					if (idx == K)
					{
						cout << i * j;
						return 0;
					}
					era[i*j] = false;
				}
			}
		}
	}

	return 0;
}
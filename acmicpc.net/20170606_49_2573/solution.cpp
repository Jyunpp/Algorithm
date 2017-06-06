#include<iostream>
using namespace std;
int arr[305][305], carr[305][305];
int n, m;
void arr_copy(int(*arr1)[305], int(*arr2)[305])
{
	for (int i = 0; i < 305; i++)
		for (int k = 0; k < 305; k++)
			arr1[i][k] = arr2[i][k];
}
void check(int y, int x)
{
	carr[y][x] = 0;

	if (carr[y][x + 1]) check(y, x + 1);
	if (carr[y][x - 1]) check(y, x - 1);
	if (carr[y + 1][x]) check(y + 1, x);
	if (carr[y - 1][x]) check(y - 1, x);
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int k = 1; k <= m; k++)
			cin >> arr[i][k];
	arr_copy(carr, arr);
	int cnt = 0;
	while (true)
	{
		int area = 0;

		for (int i = 1; i <= n; i++)
			for (int k = 1; k <= m; k++)
				if (carr[i][k])
				{
					check(i, k);
					area++;
				}

		if (area != 1)
		{
			if (area == 0) cout << 0 << endl;
			else cout << cnt << endl;

			return 0;
		}

		cnt++;
		arr_copy(carr, arr);
		for (int i = 1; i <= n; i++)
			for (int k = 1; k <= m; k++)
				if (arr[i][k] == 0)
				{
					if (arr[i][k - 1] && carr[i][k - 1]) carr[i][k - 1]--;
					if (arr[i][k + 1] && carr[i][k + 1]) carr[i][k + 1]--;
					if (arr[i - 1][k] && carr[i - 1][k]) carr[i - 1][k]--;
					if (arr[i + 1][k] && carr[i + 1][k]) carr[i + 1][k]--;
				}
		arr_copy(arr, carr);
	}
	return 0;
}
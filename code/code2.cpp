// https://www.acmicpc.net/problem/5525
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, result = 0;
	cin >> n >> m;

	string inputs;
	cin >> inputs;

	string p;
	p += "I";
	for (int i = 0; i < n; ++i)
	{
		p += "OI";
	}

	int count = 0;
	for (int i = 0; i < m-2; )
	{
		if (inputs.substr(i, 3) == "IOI")
		{
			count += 1;
			i += 2;
			if (count == n)
			{
				count -= 1;
				result += 1;
			}
		}
		else
		{
			i += 1;
			count = 0;
		}
	}
	cout << result;

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long n;
int x, ans = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&x);
		ans ^= x;
	}
	printf("%d\n", ans);
}



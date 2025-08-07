#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;
int main()
{
	unordered_set<long long> row;
	unordered_set<long long> col;
	long long n, k;
	cin >> n >> k;
	long long ans = 0;
	for (int i = 0; i < k; i++)
	{
		long long r, c;
		scanf("%d %d",&r,&c);
		/*
		if (row.find(r) == row.end() && col.find(c) == col.end())
		{
			ans += n + n - 1;
			row.insert(r);
			col.insert(c);
		}
		else if (row.find(r) == row.end() && col.find(c) != col.end())
		{
			ans += n - 1;
			row.insert(r);
		}
		else if (col.find(c) == col.end() && row.find(r) != row.end())
		{
			ans += n - 1;
			col.insert(c);
		}//这样会重复计数，比如(1,1)(1,2)(2,1)
		*/
		row.insert(r);
		col.insert(c);
	}
	ans = row.size() * n + col.size() * n - row.size() * col.size();//容斥原理
	cout << ans << endl;
	return 0;
}

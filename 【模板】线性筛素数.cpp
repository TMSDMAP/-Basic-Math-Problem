#include <iostream>
#include <vector>
using namespace std;
/*
线性筛(欧拉筛)是一种高效的素数筛选算法。核心思想为：
每个合数只会被它的最小质因数筛去一次，从而保证了时间复杂度为O(n)
*/
const int N = 1e8 + 7;
vector<int> primes;
bool is_prime[N];
void linear_sieve(int n)
{
	fill(is_prime, is_prime + n + 1, true);
	for (int i = 2; i <= n; i++)
	{
		if(is_prime[i]) {
			primes.push_back(i);
		}
		for (int p : primes) {
			if (i * p > n) break;
			is_prime[i * p] = false;
			if (i % p == 0) break; // 确保每个合数只被它的最小质因数筛去一次
		}
	}
}
/*
当你用i和p去筛ip时，ip一定是合数。
如果p能整除i，说明p是i的一个质因数，而且是最小的那个（因为p是从小到大枚举的）。
那么i可以写成：i = p × m（m是某个整数，且m≥p）
现在你要筛掉i*p = p × m × p = p × p × m
如果你继续用更大的素数q去筛iq（q>p），那么iq = i × q = p × m × q
但这个数（p × m × q）会在m × q的时候被更小的数筛掉（因为m ≤ i，q > p），所以没必要再用更大的素数去筛了
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,q;
	cin >> n >> q;
	linear_sieve(n);
	for (long long i = 0; i < q; i++)
	{
		long long k;
		cin >> k;
		cout << primes[k - 1] <<'\n'; // 输出第k个素数
	}
}
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
//区间素数筛(分段筛)

const int N = 1e6 + 10;
vector<long long> primes;
bool is_prime[N];
void linear_sieve(long long n)
{
	fill(is_prime, is_prime+ n + 1, true);
	for (long long i = 2; i <= n; i++)
	{
		if(is_prime[i]) {
			primes.push_back(i);
		}
		for (long long p : primes) {
			if (i * p > n) break;
			is_prime[i * p] = false;
			if (i % p == 0) break; // 确保每个合数只被它的最小质因数筛去一次,避免重复筛除
		}
	}
}

int main() {
	long long L, R;
	cin >> L >> R;
	long long len = R - L + 1;
	vector<bool> seg_prime(len, true);

	linear_sieve(sqrt(R)+1); // 筛出小于等于sqrt(R)的素数
	for (long long p : primes) {
		long long start = max(p * p, ((L + p - 1) / p)*p); // 确保从p的平方开始筛,例如直到5×5=25才是第一个没有被更小质数筛除的倍数
		for(long long j = start;j<=R;j+=p)
			seg_prime[j - L] = false;
	}
	if (L == 1) seg_prime[0] = false; // 1不是素数

	long long cnt = 0;
	for(int i = 0;i<len;++i)
		if (seg_prime[i]) cnt++;
	cout << cnt << endl;
	return 0;
}

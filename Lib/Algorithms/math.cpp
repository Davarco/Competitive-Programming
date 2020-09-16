#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int power(int X, int N, int P)
{
	int res = 1;
	X = X % P;
	while (N > 0)
	{
		if (N & 1)
			res = (res * X) % P;
		N = N >> 1;
		X = (X * X) % P;
	}
	return res;
}

int modinv(int N, int P)
{
	return power(N, P-2, P);
}

void binomial_coefficients()
{
	int N = 10;
	int dp[N+1][N+1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int n = 1; n <= N; n++)
	{
		dp[n][0] = 1, dp[n][n] = 1;
		for (int k = 1; k <= N-1; k++)
			dp[n][k] = dp[n-1][k-1] + dp[n-1][k];
	}
	for (int n = 0; n <= N; n++)
		PLIST(dp[n], n+1);
}

void binomial_coefficients_faster()
{
	int N = 10, K = 2, P = 13;
	if (K == 0)
		return;
	vi fac(N+1);
	fac[0] = 1;
	for (int n = 1; n <= N; n++)
		fac[n] = (fac[n-1] * n) % P;
	int ans = fac[N];
	ans = (ans * modinv(fac[K], P)) % P;
	ans = (ans * modinv(fac[N-K], P)) % P;
	cout << ans << endl;
}

void catalan_numbers()
{
	// Cat(n) = (2xN) C (N) / (N+1).
	// Cat(n+1) = (2N+2)(2N+1) / ((N+2)(N+1)) Cat(n). Cat(0) = 1.
	
	int N = 10;
	int dp[N+1];
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	for (int n = 2; n <= N; n++)
		dp[n] = (2*n)*(2*n-1) / (n+1) / n * dp[n-1];
	PLIST(dp, N+1);

	// Cat(n)
	// 1. Number of distinct binary trees with n vertices.
	// 2. Number of expressions containing n pairs of parantheses.
	// 3. Number of ways n+1 factors can be paranthesized.
	// 4. Number of ways a convex polygon can be triangulated.
	// 5. Number of monotonic paths on nxn that don't cross diagonal.
}

// O(N log log N)
void sieve_of_eratosthenes()
{
	int N = 100;
	vi sieve(N+1, true);
	vi primes;
	for (int a = 2; a <= N; a++)
		if (sieve[a])
		{
			for (int b = a*a; b <= N; b += a)
				sieve[b] = false;
			primes.push_back(a);
		}
	PLIST(primes, primes.size());	
}

// O(log N)
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

// O(log N)
int lcm(int a, int b)
{
	return a * (b / gcd(a, b));
}

// O(N log N)
void gcd_of_list()
{
	vi A = { 24, 32, 80, 152, 16 };
	int G = A[0];
	for (int i = 1; i < A.size(); i++)
		G = gcd(G, A[i]);
	cout << G << endl;
}

// O(N log N)
void lcm_of_list()
{
	vi A = { 24, 32, 80, 152, 16 };
	int L = A[0];
	for (int i = 1; i < A.size(); i++)
		L = lcm(L, A[i]);
	cout << L << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);

	binomial_coefficients();
	binomial_coefficients_faster();
	catalan_numbers();
	sieve_of_eratosthenes();
	gcd_of_list();
	lcm_of_list();
}


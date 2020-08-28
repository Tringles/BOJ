#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int p[10000001], prime[10000001], n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i <= 9; i++) {
		p[i] = true;
		p[i * 10 + i] = true;
		for (int j = 0; j <= 9; j++) {
			p[i * 100 + j * 10 + i] = true;
			p[i * 1000 + j * 100 + j * 10 + i] = true;
			for (int k = 0; k <= 9; k++) {
				p[i * 10000 + j * 1000 + k * 100 + j * 10 + i] = true;
				p[i * 100000 + j * 10000 + k * 1000 + k * 100 + j * 10 + i] = true;
				for (int q = 0; q <= 9; q++)
					p[i * 1000000 + j * 100000 + k * 10000 + q * 1000 + k * 100 + j * 10 + i] = true;
			}
		}
	}
	fill(prime + 2, prime + 10000001, 1);
	for (int i = 2; i <= 10000000; i++)
		for (int j = i * 2; j <= 10000000; j += i)
			prime[j] = 0;
	cin >> n;
	for (int i = n; i <= 10000000; i++) {
		if (p[i] && prime[i]) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
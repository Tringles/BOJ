#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
typedef pair<int, pair<int, int>> PII;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n) {
		int res = 0;
		while (n) {
			res += n % 10;
			n /= 10;
			if (!n) {
				if (!(res / 10))break;
				n = res;
				res = 0;
			}
		}
		cout << res << endl;
		cin >> n;
	}
	return 0;
}
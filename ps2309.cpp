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

int n[10], sum, det;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		cin >> n[i];
		sum += n[i];
	}
	det = sum - 100;
	sort(n, n + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == j)continue;
			if (n[i] + n[j] == det) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j)continue;
					cout << n[k] << endl;
				}
				return 0;
			}
		}
	}
	return 0;
}

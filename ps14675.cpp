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

int n, q, ind[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0, p1, p2;i < n - 1;i++) {
		cin >> p1 >> p2;
		ind[p1]++;
		ind[p2]++;
	}
	cin >> q;
	for (int i = 0, p1, p2;i < q;i++) {
		cin >> p1 >> p2;
		if (p1 == 1) {
			if (ind[p2] == 1)cout << "no" << endl;
			else cout << "yes" << endl;
		}
		else cout << "yes" << endl;
	}
	return 0;
}
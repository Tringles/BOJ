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

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		int a = 0, b = 0;
		for (int i = 0, p1, p2;i < 9;i++) {
			cin >> p1 >> p2;
			a += p1, b += p2;
		}
		if (a > b)cout << "Yonsei" << endl;
		else if (a < b)cout << "Korea" << endl;
		else cout << "Draw" << endl;
	}
	return 0;
}
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

int t, cnt;
string a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> a >> b;
		for (int i = 0; i < a.size(); i++)
			if (a[i] != b[i])cnt++;
		cout << "Hamming distance is " << cnt << '.' << endl;
		cnt = 0;
	}
	return 0;
}

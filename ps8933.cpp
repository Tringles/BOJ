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

int t, n, ans;
string str;
map<pair<int, PII>, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> str;
		int ans = 0;
		for (int i = 0; i < str.size() - n + 1; i++) {
			int a = 0, g = 0, t = 0, c = 0;
			for (int j = i; j < i + n; j++) {
				if (str[j] == 'A')a++;
				else if (str[j] == 'G')g++;
				else if (str[j] == 'T')t++;
				else c++;
			}
			ans = max(ans, ++m[{a, { g,{t,c} }}]);
		}
		cout << ans << endl;
		m.clear();
	}
	return 0;
}

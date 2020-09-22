#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<double, double> PD;
typedef pair<ll, ll> PL;
typedef pair<double, pair<double, double>> PDD;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

int n, cnt[26], ans, ctr = 9;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		reverse(str.begin(), str.end());
		int m = 1;
		for (int j = 0; j < str.size(); j++) {
			cnt[str[j] - 'A'] += m;
			m *= 10;
		}
	}
	sort(cnt, cnt + 26);
	reverse(cnt, cnt + 26);
	for (int i = 0; i < 26; i++)
		if (cnt[i])ans += cnt[i] * ctr--;
	cout << ans << endl;
	return 0;
}
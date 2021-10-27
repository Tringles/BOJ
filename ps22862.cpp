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

int n, k, s[1000005], ans, cnt, mans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0;i < n;i++)cin >> s[i];
	int l = 0, r = 1;
	if (s[l] % 2)cnt++;
	else ans++;
	mans = max(mans, ans);
	while (l < r && r < n) {
		if (s[r++] % 2)cnt++;
		else {
			ans++;
			mans = max(mans, ans);
		}
		if (cnt > k) {
			while (true) {
				if (s[l++] % 2) {
					cnt--;
					break;
				}
				else ans--;
			}
		}
	}
	cout << mans << endl;
	return 0;
}
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

ll t, n, s[500505], s2[500505];

ll func(int x, int y) {
	if (x == y)return 0;
	int mid = (x + y) >> 1;
	ll result = func(x, mid) + func(mid + 1, y);
	int i = x;
	int j = mid + 1;
	int idx = 0;
	while (i <= mid || j <= y) {
		if (i <= mid && (j > y || s[i] <= s[j]))
			s2[idx++] = s[i++];
		else {
			result += (mid - i + 1) * 1LL;
			s2[idx++] = s[j++];
		}
	}
	for (int k = x; k <= y; k++)
		s[k] = s2[k - x];
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> s[i];
	ll result = func(0, n - 1);
	cout << result << endl;
	return 0;
}
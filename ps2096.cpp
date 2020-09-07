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

int n, maxdp[3], mindp[3], maxtmp[3], mintmp[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> maxtmp[j];
			mintmp[j] = maxtmp[j];
			if (j == 1) {
				maxtmp[j] += max(maxdp[1], max(maxdp[0], maxdp[2]));
				mintmp[j] += min(mindp[1], min(mindp[0], mindp[2]));
			}
			else {
				maxtmp[j] += max(maxdp[1], maxdp[j]);
				mintmp[j] += min(mindp[1], mindp[j]);
			}
		}
		for (int j = 0; j < 3; j++) {
			maxdp[j] = maxtmp[j];
			mindp[j] = mintmp[j];
		}
	}
	sort(maxdp, maxdp + 3);
	sort(mindp, mindp + 3);
	cout << maxdp[2] << ' ' << mindp[0] << endl;
	return 0;
}

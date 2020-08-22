#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, a[100001], b[100001], ans, idx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	for (int i = 1; i <= 5; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i == a[j] || i == b[j])cnt++;
			else cnt = 0;
			if (ans < cnt) {
				ans = cnt;
				idx = i;
			}
		}
	}
	cout << ans << ' ' << idx << endl;
	return 0;
}
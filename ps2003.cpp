#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, m, s[10001], ans, cur;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) {
		cur = 0;
		for (int j = i; j < n; j++) {
			cur += s[j];
			if (cur == m)ans++;
		}
	}
	cout << ans << endl;
    return 0;
}

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

int n, p, w, l, g, ans;
char state;
bool flag;
string player;
map<string, int> hack;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> p >> w >> l >> g;
	for (int i = 0; i < p; i++) {
		cin >> player >> state;
		if (state == 'W')
			hack[player] = w;
		else hack[player] = -l;
	}
	for (int i = 0; i < n; i++) {
		cin >> player;
		if (hack[player]) ans += hack[player];
		else ans -= l;
		if (ans < 0)ans = 0;
		if (ans >= g) {
			flag = true;
		}
	}
	if (flag)cout << "I AM NOT IRONMAN!!" << endl;
	else cout << "I AM IRONMAN!!" << endl;
	return 0;
}

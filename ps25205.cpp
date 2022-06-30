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

int n;
string str, det = "rsefaqtdwczxvg";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> str;
	for (int i = 0;i < det.size();i++) {
		if (str[n - 1] == det[i]) {
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}
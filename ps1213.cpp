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

int cnt[29], idx;
char str[55];
bool flag;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < strlen(str); i++)
		cnt[str[i] - 'A']++;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2 && flag) {
			cout << "I'm Sorry Hansoo" << endl;
			return 0;
		}
		if (cnt[i] % 2) {
			flag = true;
			idx = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 2) {
			for (int j = 0; j < cnt[i] / 2; j++)
				cout << (char)(i + 'A');
		}
	}
	if (flag)cout << (char)(idx + 'A');
	for (int i = 25; i >= 0; i--) {
		if (cnt[i] >= 2)
			for (int j = 0; j < cnt[i] / 2; j++)
				cout << (char)(i + 'A');
	}
	cout << endl;
	return 0;
}

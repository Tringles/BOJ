#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, l, s[1005], cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> l;
	for (int i = 0; i < n; i++)cin >> s[i];
	sort(s, s + n);
	l--;
	int lo = s[0];
	for (int i = 0; i < n; i++)
		if (lo + l < s[i])lo = s[i], cnt++;
	cout << cnt + 1 << endl;
	return 0;
}
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

int a[4], b[2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0;i < 4;i++)cin >> a[i];
	cin >> b[0] >> b[1];
	sort(a, a + 4);
	sort(b, b + 2);
	cout << a[1] + a[2] + a[3] + b[1] << endl;
	return 0;
}
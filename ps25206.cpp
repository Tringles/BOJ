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

string str, g;
double s, sum, cnt;

double convert(string s) {
	if (s == "A+")return 4.5;
	if (s == "A0")return 4.0;
	if (s == "B+")return 3.5;
	if (s == "B0")return 3.0;
	if (s == "C+")return 2.5;
	if (s == "C0")return 2.0;
	if (s == "D+")return 1.5;
	if (s == "D0")return 1.0;
	return 0.0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0;i < 20;i++) {
		cin >> str >> s >> g;
		if (g != "P") {
			cnt += s;
			sum += s * convert(g);
		}
	}
	cout << fixed << setprecision(5) << sum / cnt << endl;
	return 0;
}
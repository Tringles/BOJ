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

string str;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (i + 2 <= str.size()) {
			if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=') {
				cnt++;
				i += 2;
				continue;
			}
		}
		if (i + 1 <= str.size()) {
			if (str[i] == 'c' && str[i + 1] == '=')cnt++, i++;
			else if (str[i] == 'c' && str[i + 1] == '-')cnt++, i++;
			else if (str[i] == 'd' && str[i + 1] == '-')cnt++, i++;
			else if (str[i] == 'l' && str[i + 1] == 'j')cnt++, i++;
			else if (str[i] == 'n' && str[i + 1] == 'j')cnt++, i++;
			else if (str[i] == 's' && str[i + 1] == '=')cnt++, i++;
			else if (str[i] == 'z' && str[i + 1] == '=')cnt++, i++;
			else cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}

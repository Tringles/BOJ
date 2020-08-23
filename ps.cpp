#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, s[28];

char func(int cur) {
	if (cur == 1)return 'm';
	if (cur == 2 || cur == 3)return 'o';
	int i = 0;
	while (s[i] < cur)i++;
	if (cur - s[i - 1] == 1)return 'm';
	if (cur - s[i - 1] <= i + 3)return 'o';
	return func(cur - s[i - 1] - (i + 3));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	s[0] = 3;
	for (int i = 1; i < 28; i++)
		s[i] = s[i - 1] * 2 + i + 3;
	cout << func(n) << endl;
	return 0;
}
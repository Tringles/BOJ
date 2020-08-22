#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, cnt;

void func(int cur) {
    if (cur == 1)return;
    if (cur % 2) {
        cnt += (cur / 2) * (cur / 2 + 1);
        func(cur / 2);
        func(cur / 2 + 1);
    }
    else {
        cnt += (cur / 2) * (cur / 2);
        func(cur / 2);
        func(cur / 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    func(n);
    cout << cnt << endl;
    return 0;
}

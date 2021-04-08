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
string str;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    getline(cin, str);
    while (n--) {
        bool flag = false;
        getline(cin, str);
        int l = 0, r = str.size() - 1;
        while(l <= r) {
            if(str[l] > 'Z') str[l]-=32;
            if(str[r] > 'Z') str[r]-=32;
            if (str[l] != str[r]) {
                cout << "No" << endl;
                flag = true;
                break;
            }
            l++, r--;
        }
        if (!flag) cout << "Yes" << endl;
    }
    return 0;
}

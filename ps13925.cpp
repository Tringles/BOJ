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

int n,m,q,p1,p2,p3,p4;
struct node{
    ll val,mlazy,alazy;
}seg[100004*4];

void propagate(int lo, int hi, int node){
    if(seg[node].mlazy!=1){
        seg[node].val=(seg[node].val * seg[node].mlazy)%MOD;
        if(lo != hi){
            seg[node*2].mlazy = (seg[node*2].mlazy * seg[node].mlazy)%MOD;
            seg[node*2].alazy = (seg[node*2].alazy * seg[node].mlazy)%MOD;
            seg[node*2+1].mlazy = (seg[node*2+1].mlazy * seg[node].mlazy)%MOD;
            seg[node*2+1].alazy = (seg[node*2+1].alazy * seg[node].mlazy)%MOD;
        }
        seg[node].mlazy = 1;
    }
    if(seg[node].alazy){
        seg[node].val = (seg[node].val + (hi - lo + 1) * seg[node].alazy)%MOD;
        if(lo != hi){
            seg[node*2].alazy = (seg[node*2].alazy + seg[node].alazy)%MOD;
            seg[node*2+1].alazy = (seg[node*2+1].alazy + seg[node].alazy)%MOD;
        }
        seg[node].alazy = 0;
    }
}
ll update_add(int lo, int hi, int node, ll val, int x, int y){
    propagate(x, y, node);
    if(hi<x||y<lo)return seg[node].val;
    if(lo<=x&&y<=hi){
        seg[node].alazy=val;
        propagate(x, y, node);
        return seg[node].val;
    }
    int mid = (x+y)>>1;
    return seg[node].val=(update_add(lo, hi, node*2, val, x, mid) + update_add(lo, hi, node*2+1, val, mid+1, y))%MOD;
}
ll update_mul(int lo, int hi, int node, ll val, int x, int y){
    propagate(x, y, node);
    if(hi<x||y<lo)return seg[node].val;
    if(lo<=x&&y<=hi){
        seg[node].mlazy=val;
        propagate(x, y, node);
        return seg[node].val;
    }
    int mid = (x+y)>>1;
    return seg[node].val=(update_mul(lo, hi, node*2, val, x, mid) + update_mul(lo, hi, node*2+1, val, mid+1, y))%MOD;
}
ll update(int lo, int hi, int node, ll val, int x, int y){
    propagate(x, y, node);
    if(hi<x||y<lo)return seg[node].val;
    if(lo<=x&&y<=hi){
        seg[node].mlazy=0;
        seg[node].alazy=val;
        propagate(x, y, node);
        return seg[node].val;
    }
    int mid = (x+y)>>1;
    return seg[node].val = (update(lo, hi, node*2, val, x, mid) + update(lo, hi, node*2+1, val, mid+1, y))%MOD;
}
ll query(int lo, int hi, int node, int x, int y){
    propagate(x, y, node);
    if(hi<x||y<lo)return 0;
    if(lo<=x&&y<=hi)return seg[node].val;
    int mid = (x+y)>>1;
    return (query(lo, hi, node*2, x, mid) + query(lo, hi, node*2+1, mid+1, y))%MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>p1;
        update(i,i,1,p1,1,n);
    }
    cin>>q;
    while(q--){
        cin>>p1;
        if(p1 == 1){
            cin>>p2>>p3>>p4;
            update_add(p2,p3,1,p4,1,n);
        }
        else if (p1 == 2){
            cin>>p2>>p3>>p4;
            update_mul(p2,p3,1,p4,1,n);
        }
        else if (p1 == 3){
            cin>>p2>>p3>>p4;
            update(p2,p3,1,p4,1,n);
        }
        else{
            cin>>p2>>p3;
            cout<<query(p2,p3,1,1,n)<<endl;
        }
    }
    return 0;
}

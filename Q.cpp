 #include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>  ordered_set;

 #define okk order_of_key 

 #define pb push_back
 #define popb pop_back
 #define popf pop_front
 #define fr(a,b) for(int i = a; i < b; i++)
 #define rep(i,a,b) for(int i = a; i < b; i++)
 #define rev(i,a,b) for(int i = a; i > b; i--)
 #define setpr(x) cout << setprecision(x) fixed
 #define F first
 #define S second
 #define pii pair<int, int>
 #define vii vector<pii>
 #define vi vector<int>
 #define vvi vector<vi>
 #define vii vector<pii>
 #define vd vector<double>
 #define vvd vector<vd>
 #define seevec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
 #define inf (1LL<<60)
 #define all(x) (x).begin(), (x).end()
 #define prDouble(x) cout << fixed << setprecision(10) << x
 #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 using namespace std;
 #define int long long
 #define ll long long
 #define endl '\n'
 const int MOD = 1e9+7;

mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

/*debug start*/
 void __print32_t(int32_t x) {cerr << x;}
void __print32_t(long x) {cerr << x;}
void __print32_t(long long x) {cerr << x;}
void __print32_t(unsigned x) {cerr << x;}
void __print32_t(unsigned long x) {cerr << x;}
void __print32_t(unsigned long long x) {cerr << x;}
void __print32_t(float x) {cerr << x;}
void __print32_t(double x) {cerr << x;}
void __print32_t(long double x) {cerr << x;}
void __print32_t(char x) {cerr << '\'' << x << '\'';}
void __print32_t(const char *x) {cerr << '\"' << x << '\"';}
void __print32_t(const string &x) {cerr << '\"' << x << '\"';}
void __print32_t(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print32_t(const pair<T, V> &x) {cerr << '{'; __print32_t(x.first); cerr << ','; __print32_t(x.second); cerr << '}';}
template<typename T>
void __print32_t(const T &x) {int32_t f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print32_t(i); cerr << "}";}
void _print32_t() {cerr << "]\n";}
template <typename T, typename... V>
void _print32_t(T t, V... v) {__print32_t(t); if (sizeof...(v)) cerr << ", "; _print32_t(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print32_t(x)
#else
#define debug(x...)
#endif
 /*debug end*/

template <typename ele_type> ostream& operator<<(ostream& os, const vector<ele_type>& v){
    for (auto itr : v)
        os << itr << " ";
    os << "\n";
    return os;
}

int fastpow(int a, int b){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % MOD;
        b /= 2; a = (a*a) % MOD;
    }
    return ans;
}

//define the global variables here
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
template<class T>
class SegTree {
private:
    const T id = 0;
    vector<T> segtree;
 
public:
    int len;
    SegTree(int l){
        int n = 1 << log2_floor(l);
        if (l != n) {
            n = 1 << (log2_floor(l) + 1);
        }
        len = n;
 
        segtree.resize(len * 2, id);
    }
 
    void update(int ind, T val) {
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = max(segtree[ind], segtree[ind ^ 1]);
        }
    }
    void display() {
        cout << len << segtree.size() << "\n";
    }
    T _query(int node, int nL, int nR, int l, int r) {
        if (l > r) return id;
        if (l == nL && r == nR) {
 
            return segtree[node];
        }
        int m = (nL + nR) / 2;
        return max(_query(node * 2, nL, m, l, min(r, m)), _query(node * 2 + 1, m + 1, nR, max(l, m + 1), r));
    }
    T query(int l, int r) {
        return _query(1, 0, len - 1, l, r);
    }
 
};



void solve()
{
    int n;
    cin >> n;
    vi h, a; h.pb(0), a.pb(0);
    seevec(h, n);
    seevec(a, n);
    //weighted LIS
    vi dp(n+1, 0);
    SegTree<int> st(n+1);
    fr(1, n+1){
        // rep(j, 1, i){
        //     if (h[i] > h[j]){
        //         dp[i] = max(dp[i], dp[j] + a[i]);
        //     }
        // }
        //optimization using seg tree
        dp[i] = st.query(1, h[i]-1) + a[i];
        st.update(h[i], dp[i]);
    }
    cout << *max_element(all(dp)) << endl;
}
 
int32_t main() {
    fast_io;
    int t=1;
    //cin >> t;
    while(t--)
    {
       solve();
    }
    return 0;
}
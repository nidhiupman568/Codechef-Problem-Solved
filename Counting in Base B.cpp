#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL) , cout.tie(NULL)
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int , int> >
#define vc vector<char>
#define vvc vector<vector<char> >
#define pii pair<int , int>
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define pb push_back
#define ff first
#define ss second
#define fr(i,n) for(int i=0; i<(n); i++)
#define dbg(var) cout<<#var<<" : "<<var<<"\n"
#define all(v) v.begin(),v.end()
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define set_bits(x) __builtin_popcountll(x)  // number of set bits
#define first_set(x) __builtin_ctzll(x)      // ...001000 -> 3 
#define last_set(x) __builtin_ctzll(x)       // 00010000 00000000 00000000 00000000 -> 3 (for 32 bit int), not very useful tho

using namespace std;
const int MOD=1e9+7;      // Hardcoded, directly change from here for functions!

// get a random number in range (a,b)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

// using namespace __gnu_pbds;
using __gnu_pbds::tree;
using __gnu_pbds::rb_tree_tag;
using __gnu_pbds::tree_order_statistics_node_update;
using __gnu_pbds::null_type;

// _GLIBCXX_DEBUG must not be defined otherwise some internal check will fail
#undef _GLIBCXX_DEBUG

template <typename K, typename V, typename Comp = less<K>>
using indexed_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename Comp = less<K>>
using indexed_set = indexed_map<K, null_type, Comp>;

// ¡¡IMPORTANT!! (for using less_equals<K>)
// using less_equals<K> makes lower_bound works as upper_bound and vice-versa
// for erase use: any.erase(any.find_by_order(any.order_of_key(val)));
// don't use .find() because it will always return .end()
template <typename K, typename V, typename Comp = less_equal<K>>
using indexed_multimap = indexed_map<K, V, Comp>;

template <typename K, typename Comp = less_equal<K>>
using indexed_multiset = indexed_map<K, null_type, Comp>;

// find_by_order(k): returns an iterator to the (k+1)-th largest element (0-based)
// order_of_key(num):  #elements in the set strictly smaller "num"

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const set<typC> &a) { for (auto it:a) cout<<it << " "; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const multiset<typC> &a) { for (auto it:a) cout<<it << " "; return cout; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const map<typC , typD> &m) { for (auto it:m) cout<<it.ff << " : " << it.ss << endl; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<vector<typC>> &a) { int n = a.size(); int m = a[0].size(); for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout << a[i][j] << ' ';} if(i != n-1)cout << endl;} return cout;}
// ===================================END Of the input module ==========================================


const int MX_SZ = 1e5 + 7;
int fact[MX_SZ];
int ifact[MX_SZ];

int poww(int x, int y){
	int ans=1;
	while(y>0){
		if(y&1){
			ans = (ans*x)%MOD;
		}
		y >>= 1;
		x = (x*x)%MOD;
	}
	return ans%MOD;
}

int C(int x, int y){
	if(x < y)return 0;
	return (fact[x] * ifact[y]%MOD * ifact[x-y]%MOD) % MOD;
}

int n,b,k;

int func(vi &a){
    
    vector<bool> have(b , 0);

    // indexed_set<int> dist;

    int ans = 0;
    for(int i=0;i<n;i++){
        int lim = a[i];
        if(lim == 0)continue;

        // i go below lim at "i"th pos

        int x = 0;
        int used = 0;
        for(int j=0;j<b;j++){
            if(have[j] == 1){
                used++;
                if(j < lim)x++;
            }
        }

        // int x = 0;
        // if(dist.size() > 0)x = dist.order_of_key(lim);
        // int used = dist.size();

        if(used > k)break;
        // k >= used now

        // case 1: it is different from already used
        if(k >= (used+1) && n-1-i >= k-(used+1)){
            // first choose a new number for "i"th pos in (lim-x) ways
            // then, choose the new k - (used+1) numbers for making it exactly "k" distinct 
            int case1 = ((lim-x) % MOD * C(b-(used+1) , k-(used+1)) % MOD) % MOD;
            // n-1-i slots to be used by k numbers, k-(used+1) to be used atleast once 

            // USE INCLUSION EXCLUSION!! 
            int all_new_atleast_once = 0;
            for(int nw=0;nw<=k-(used+1);nw++){
                // nw = number of "new" digits used 0 times

                int ways = (C(k-(used+1) , nw) % MOD * poww(k - nw , n-1-i) % MOD) % MOD;

                if(nw%2 == 0)all_new_atleast_once += ways;
                else all_new_atleast_once -= ways;

                all_new_atleast_once = (all_new_atleast_once % MOD + MOD) % MOD;
            }

            case1 = (case1 * all_new_atleast_once)%MOD;

            ans = (ans + case1 % MOD) % MOD;
        }
        // case 2 : it is one that was already used
        if(n-1-i >= k-used){
            // first choose a new number for "i"th pos in (x) ways
            // then, choose the new k - (used) numbers for making it exactly "k" distinct 
            int case2 = (x % MOD * C(b-(used) , k-(used)) % MOD) % MOD;
            // n-1-i slots to be used by k numbers, k-(used) to be used atleast once 

            int all_new_atleast_once = 0;
            for(int nw=0;nw<=k-(used);nw++){
                // nw = number of "new" digits used 0 times

                int ways = (C(k-(used) , nw) % MOD * poww(k - nw , n-1-i) % MOD) % MOD;

                if(nw%2 == 0)all_new_atleast_once += ways;
                else all_new_atleast_once -= ways;

                all_new_atleast_once = (all_new_atleast_once % MOD + MOD) % MOD;
            }
            case2 = (case2 * all_new_atleast_once)%MOD;
            ans = (ans + case2 % MOD) % MOD;
        }
        have[a[i]] = 1;
        // dist.insert(a[i]);
    }
    return ans%MOD;
}

void solve(){
    cin >> n >> b >> k;
    vi l(n) , r(n);
    cin >> l >> r; 

    // https://www.codechef.com/START139A/problems/COUNTBASEB

    // need exactly k distinct numbers , length n , base b
    // digit dp?
    // no a simgle iteration is enough

    // got the main ideas but got stuck in thinking inc-exc takes 2^b time!

    // aim : find the #numbers < r,l satisfying condition
    // iterate from 0 to n-1, and say at "i"th pos, number becomes smaller
    // then, case 1: it is different from already used OR case 2: it is from something already used
    // just use a bool of b numbers or a indexed_set to store the elements already used

    // got stuck here : how to use k numbers to fill n-i-1 gaps such that the 
    // "new" numbers(k-(already used) of them) occur atleast once
    // USE INCUSION-EXCLUSION FOR THIS!! it is NOT 0(2^b) , it is simply 0(b)  

    int ans1 = func(l);
    int ans2 = func(r);

    // dbg(ans1);

    set<int> distcnt;
    fr(i,n)distcnt.insert(r[i]);
    if(distcnt.size() == k)ans2++;

    ans2 %= MOD;
    // dbg(ans2);

    cout << (ans2 - ans1 + MOD) % MOD << endl;

    // CLEAR ALL GLOBAL VARIABLES(use it at the end/start of this function)
}

int32_t main()
{
    FAST;
    auto begin = std::chrono::high_resolution_clock::now();
    
    fact[0] = 1;
    ifact[0] = 1;
    for(int i=1;i<MX_SZ;i++){
    	fact[i] = (fact[i-1]*i)%MOD;
    	ifact[i] = poww(fact[i] , MOD-2)%MOD;
    }

    int T;
    cin >> T;
    for (int _=1;_<=T;_++)
    {
        // cout << "Case #" << _ << ": " << endl;
        solve();
    }
    return 0;

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}

#include "bits/stdc++.h"
using namespace std;
#define all(x) x.begin(),x.end()
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << p.first << " " << p.second; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#define ASSERT(...) 42
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int oo = 1e9;
const long long MD =  998244353;
template<long long MOD=MD> struct mdint {
    int d;
    mdint () {d=0;}
    mdint (long long _d) : d(_d%MOD){
        if(d<0) d+=MOD;
    };
    friend mdint& operator+=(mdint& a, const mdint& o) {
        a.d+=o.d; if(a.d>=MOD) a.d-=MOD;
        return a;
    }
    friend mdint& operator-=(mdint& a, const mdint& o) {
        a.d-=o.d; if(a.d<0) a.d+=MOD;
        return a;
    }
    friend mdint& operator*=(mdint& a, const mdint& o) {
        return a = mdint((ll)a.d*o.d);
    }
    mdint operator*(const mdint& o) const {
        mdint res = *this;
        res*=o;
        return res;
    }
    mdint operator+(const mdint& o) const {
        mdint res = *this;
        res+=o;
        return res;
    }
    mdint operator-(const mdint& o) const {
        mdint res = *this;
        res-=o;
        return res;
    }
    mdint operator^(long long b) const {
        mdint tmp = 1;
        mdint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    friend mdint operator/=(mdint& a, const mdint& o) {
        a *= (o^(MOD-2));
        return a;
    }
    mdint operator/(const mdint& o) {
        mdint res = *this;
        res/=o;
        return res;
    }
    bool operator==(const mdint& o) { return d==o.d;}
    bool operator!=(const mdint& o) { return d!=o.d;}
    friend istream& operator>>(istream& c, mdint& a) {return c >> a.d;}
    friend ostream& operator<<(ostream& c, const mdint& a) {return c << a.d;}
};
using  mint = mdint<MD>;
typedef mint cd;
void revperm(cd* in, int n) {
    for(int i=0,j=0;i<n;++i) {
        if(i<j) swap(in[i],in[j]);
        for(int k = n >> 1; (j ^= k) < k; k >>= 1);
    }
}
const int mxN = 1<<19;
cd w[mxN+1]; // stores w^j for each j in [0,n-1]
void precomp() {
    w[0] = 1;
    int pw = (MD-1)/mxN;
    w[1] = mint(3)^pw;
    for(int i= 2;i<=mxN;++i) {
        w[i] = w[i-1]*w[1];
    }
}
void fft(cd* in, int n, bool reverse=false) {
    int lg = __lg(n);
    assert(1<<lg == n);
    int stride = mxN/n;
    revperm(in,n);
    for(int s=1;s<=lg;++s) {
        int pw = 1<<s;
        int mstride = stride*(n>>s);
        for(int j=0;j<n;j+=pw) {
            // do FFT merging on out array
            cd* even = in+j, *odd = in+j+pw/2;
            for(int i=0;i<pw/2;++i) {
                cd& power = w[reverse?mxN-mstride*i:mstride*i];
                auto tmp = power*odd[i];
                odd[i] = even[i] - tmp;
                even[i] = even[i] + tmp;
            }
        }
    }
    if(reverse) {
        mint fac = mint(1)/n;
        for(int i=0;i<n;++i) in[i]=in[i]*fac;
    }
}

vector<cd> polymul(vector<cd> a, vector<cd> b) {
    int n = a.size(), m = b.size(), ptwo = 1;
    while(ptwo<(n+m)) ptwo*=2;
    a.resize(ptwo), b.resize(ptwo);
    fft(a.data(),ptwo); 
    fft(b.data(),ptwo);
    for(int i=0;i<ptwo;++i) 
        a[i] = a[i]*b[i];
    fft(a.data(),ptwo,true);
    a.resize(n+m-1);
    return a;
}
typedef mint base;
typedef vector<mint> polyn;
void solve() {
    int n,m,k; cin >> n >> m >> k;
    vector<base> w(n/2);
    for(auto& i : w) cin >> i;
    base sum=0;
    for(auto& i : w) sum+=i;
    assert(sum.d!=0);
    auto isum = base(1)/sum;
    for(auto& i : w) i*=isum;
    w.insert(w.begin(),0);
    int e = k-1;
    polyn res = {1};
    auto a = w;
    while(e) {
        if(e&1) {
            res = polymul(res,a);
            res.resize((n+1)/2);

        }
        a = polymul(a,a);
        a.resize((n+1)/2);
        e/=2;
    }
    // auto res = polyn(w).pow_bin(k-1,(n+3)/2);
    base prob=0;
    for(int i=0;i<=(n-1)/2;++i) {
        prob+=res[i]*w[i];
    }
    prob*=(base(1)/base(2))^k;
    prob*=2; // 2 ways of traversing cycle
    prob*=k; // k start points on the cycle
    // prob is probability that from a certain point P_1
    // the next k passes form a tiki taka.
    // a tiki taka is precisely a convex polygon traversed on clockwise or counterclockwise order
    // which doesn't enclose the centre of the circle. So it must be fully contained in a range of coordinates of at most 0...(n-1)/2
    // in a sequence of m moves, there are m-k+1 contiguous subsequences of length k
    // so expected value of number of tiki taka's is prob(tiki taka) *(m-k+1)
    cout << (prob*base(max(0,m-k+1))) << '\n';
    

}
int main() {
    precomp();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}

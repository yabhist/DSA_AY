/*
const ll mod=998244353;
ll binpow_mod(ll a ,ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
*/

/*
ll binpow(ll a, ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
        {
            res*=a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}
*/

/*DSU
vector<ll>parent,Size;
void make(ll v)
{
    parent[v]=v;
    Size[v]=1;
}
ll find(ll v)
{
    if(v==parent[v])return v;
    return parent[v]=find(parent[v]);
}
bool Union(ll a, ll b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        if(Size[a]<Size[b])swap(a,b);
        parent[b]=a;
        Size[a]+=Size[b];
        Size[b]=0;
        return true;
    }
    return false;

}
parent.assign(n,-1);
iota(parent.begin(),parent.end(),0ll);
Size.assign(n,1);
*/

/*FACT
const ll NMAX=2e5,mod=998244353;
ll factmod[NMAX+5],invmod[NMAX+5],invfactmod[NMAX+5];

ll BC(ll n, ll k)
{
    if(k<0 || k>n){
        return 0;
    }
    return factmod[n] * invfactmod[k] % mod * invfactmod[n-k] % mod;
}

factmod[0]=invmod[0]=invfactmod[0]=factmod[1]=invmod[1]=invfactmod[1]=1;
for(ll i=2;i<=NMAX;i++) factmod[i] = factmod[i-1] * i % mod;
for(ll i=2;i<=NMAX;i++) invmod[i] = mod - mod / i * invmod[mod%i] % mod;
for(ll i=2;i<=NMAX;i++) invfactmod[i] = invfactmod[i-1] * invmod[i] % mod;

factmod[0] = 1;
for(ll i = 1; i <= NMAX; i++) factmod[i] = factmod[i - 1] * i % mod;
invfactmod[NMAX] = binpow_mod(factmod[NMAX], mod - 2);
for(ll i = NMAX - 1; i >= 0; i--) invfactmod[i] = invfactmod[i + 1] * (i + 1) % mod;
*/

/*TOT
ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

ll binpow_totient(ll a ,ll b)
{
    a %= mod;
    long long res = 1;
    b=b%tot;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
*/

/*DIJKSTRA
vector<vector<vector<ll>>>adj;
priority_queue <vector<ll> ,vector<vector<ll>> ,greater<vector<ll>>> pq;
vector<ll> dis(n,1e18);
dis[0]=0;
pq.push({0,0});
while(!pq.empty())
{
    ll dist=pq.top()[0];
    ll prev=pq.top()[1];
    pq.pop();
    if(dis[prev]!=dist) continue;
    for(auto it:adj[prev])
    {
        ll next=it[0];
        ll nexdist=it[1];
        if(dis[next]> dist + nexdist)
        {
            dis[next]=dist + nexdist;
            pq.push({dis[next],next});
        }
    }
}
adj.assign(n,vector<vector<ll>>());
*/

/*

struct binary_indexed_tree{
    ll N;
    vector<ll> bit;
    binary_indexed_tree(ll n):N(n){
        bit.resize(N+1,0);
    }
    ll addition(ll x,ll y){
        return (x+y);
    }
    void add(ll x, ll a){
        x++;
        for(x;x<=N;x+=(x&-x)) bit[x]=addition(bit[x],a);
    }
    ll sum(ll x){
        x++;
        ll res=0;
        for(x;x>0;x-=(x&-x)) res=addition(res,bit[x]);
        return res;
    }
};
ll compress(vector<ll>&A){
    map<ll,ll>mp;
    for(ll i=0;i<A.size();i++){
        mp[A[i]]=0;
    }
    ll ct=0;
    for(auto &i:mp){
        i.second=ct++;
    }
    for(ll i=0;i<A.size();i++){
        A[i]=mp[A[i]];
    }
    return ct;
}
*/

/*LCA
vector<ll>lvl;
vector<vector<ll>>dp,adj;
ll LGN;
void dfs(ll u, ll p){
    lvl[u]=lvl[p]+1;
    dp[u][0]=p;
    for(ll i=1;i<=LGN;i++){
        dp[u][i]=dp[dp[u][i-1]][i-1];
    }
    for(ll i=0;i<adj[u].size();i++){
        ll v=adj[u][i];
        if(v==p) continue;
        dfs(v,u);
    }
}
ll lca(ll u, ll v){
    if(lvl[u]<lvl[v]){
        swap(u,v);
    }
    ll diff=lvl[u]-lvl[v];
    for(ll i=0;i<=LGN;i++){
        if((1<<i)&diff){
            u=dp[u][i];
        }
    }
    if(u==v){
        return u;
    }
    for(ll i=LGN;i>=0;i--){
        if(dp[u][i]!=dp[v][i]){
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    return dp[u][0];
}
LGN=log2l(n);
adj.assign(n,vector<ll>());
dp.assign(n,vector<ll>(LGN+1));
lvl.assign(n,0);
*/

/*Mint
template<const ll& MOD>
struct Mint {
    using T = typename decay<decltype(MOD)>::type; T v;
    Mint(ll v = 0) { if(v < 0) v = v % MOD + MOD; if(v >= MOD) v %= MOD; this->v = T(v); }
    Mint(uint64_t v) { if (v >= MOD) v %= MOD; this->v = T(v); }
    Mint(int v): Mint(ll(v)) {}
    Mint(unsigned v): Mint(uint64_t(v)) {}
    explicit operator int() const { return v; }
    explicit operator ll() const { return v; }
    explicit operator uint64_t() const { return v; }
    friend istream& operator>>(istream& in, Mint& m) { ll v_; in >> v_; m = Mint(v_); return in; }
    friend ostream& operator<<(ostream& os, const Mint& m) { return os << m.v; }

    static T inv(T a, T m) {
        T g = m, x = 0, y = 1;
        while(a != 0) {
            T q = g / a;
            g %= a; swap(g, a);
            x -= q * y; swap(x, y);
        } return x < 0? x + m : x;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif // x must be less than 2^32 * m
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x), quot, rem;
        asm("divl %4\n" : "=a" (quot), "=d" (rem) : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    Mint inv() const { return Mint(inv(v, MOD)); }
    Mint operator-() const { return Mint(v? MOD-v : 0); }
    Mint& operator++() { v++; if(v == MOD) v = 0; return *this; }
    Mint& operator--() { if(v == 0) v = MOD; v--; return *this; }
    Mint operator++(int) { Mint a = *this; ++*this; return a; }
    Mint operator--(int) { Mint a = *this; --*this; return a; }
    Mint& operator+=(const Mint& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Mint& operator-=(const Mint& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Mint& operator*=(const Mint& o) { v = fast_mod(uint64_t(v) * o.v); return *this; }
    Mint& operator/=(const Mint& o) { return *this *= o.inv(); }
    friend Mint operator+(const Mint& a, const Mint& b) { return Mint(a) += b; }
    friend Mint operator-(const Mint& a, const Mint& b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint& a, const Mint& b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint& a, const Mint& b) { return Mint(a) /= b; }
    friend bool operator==(const Mint& a, const Mint& b) { return a.v == b.v; }
    friend bool operator!=(const Mint& a, const Mint& b) { return a.v != b.v; }
    friend bool operator<(const Mint& a, const Mint& b) { return a.v < b.v; }
    friend bool operator>(const Mint& a, const Mint& b) { return a.v > b.v; }
    friend bool operator<=(const Mint& a, const Mint& b) { return a.v <= b.v; }
    friend bool operator>=(const Mint& a, const Mint& b) { return a.v >= b.v; }
    Mint operator^(ll p) {
        if(p < 0) return inv() ^ -p;
        Mint a = *this, res{1}; while(p > 0) {
            if(p & 1) res *= a;
            p >>= 1; if(p > 0) a *= a;
        } return res;
    }
};

ll MOD = (ll)1e9 + 7;
// ll MOD = 998244353;

using mint = Mint<MOD>;

vector<mint> fact,ifact;

mint C(ll n, ll k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((ll) fact.size() < n + 1) {
    if (fact.empty()) {
      fact = ifact = {1};
      continue;
    }
    fact.push_back(fact.back() * (ll) fact.size());
    ifact.push_back(1 / fact.back());
  }
  return fact[n] * ifact[k] * ifact[n - k];
}
*/

/*
ll mx=32000;
vector<bool> prime(mx+1,1);
prime[0]=0,prime[1]=0;
for(ll i=2;i*i<=mx;i++)
{
    if(prime[i])
    {
        for(ll j=i*i;j<=mx;j+=i)
        {
            prime[j]=0;
        }
    }
}

vector<ll>pFactorOf;
pFactorOf.assign(mx+1,0);
iota(pFactorOf.begin(),pFactorOf.end(),0ll);
for(ll i=2;i*i<=mx;i++)
{
    if((pFactorOf[i]==i))
    {
        for(ll j=i*i;j<=mx;j+=i)
        {
            if(pFactorOf[j]==j) pFactorOf[j]=i;
        }
    }
}
*/

/*
vector<ll> segtree;
void build_segtree(vector<ll>&a,ll low, ll high, ll pos)
{
    if(low==high)
    {
        segtree[pos]=a[low];
    }
    else
    {
        ll mid=(low+high)/2;
        build_segtree(a,low,mid,2*pos+1);
        build_segtree(a,mid+1,high,2*pos+2);
        segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
    }
}
ll query(ll ql, ll qr, ll low, ll high, ll pos)
{
    if(ql>high || qr<low)
    {
        return 1e18;
    }
    if(low>=ql && high<=qr)
    {
        return segtree[pos];
    }
    ll mid=(low+high)/2;
    return min(query(ql,qr,low,mid,2*pos+1),query(ql,qr,mid+1,high,2*pos+2));
}
void update(ll i, ll val, ll low, ll high, ll pos)
{
    if(low==high)
    {
        segtree[pos]=val;
    }
    else
    {
        ll mid=(low+high)/2;
        if(i<=mid)
        {
            update(a,i,val,low,mid,2*pos+1);
        }
        else
        {
            update(a,i,val,mid+1,high,2*pos+2);
        }
        segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
    }
}
segtree.assign(4*n+1,0);
*/

/*
vector<ll> segtree;
void build_segtree(vector<ll>&a, ll low, ll high, ll pos)
{
    if(low==high)
    {
        segtree[pos]=a[low];
    }
    else
    {
        ll mid=low+(high-low)/2;
        build_segtree(a,low,mid,2*pos+1);
        build_segtree(a,mid+1,high,2*pos+2);
        segtree[pos]=segtree[2*pos+1]+segtree[2*pos+2];
    }
}

ll query(ll ql, ll qr, ll low, ll high, ll pos)
{
    if(low>=ql && high<=qr)
    {
        return segtree[pos];
    }
    if(high<ql || low>qr)
    {
        return 0;
    }
    ll mid=low+(high-low)/2;
    return query(ql,qr,low,mid,2*pos+1)+query(ql,qr,mid+1,high,2*pos+2);
}

void update(ll i, ll val, ll low, ll high, ll pos)
{
    if(low==high)
    {
        segtree[pos]=val;
    }
    else
    {
        ll mid=(low+high)/2;
        if(i<=mid)
        {
            update(a,i,val,low,mid,2*pos+1);
        }
        else
        {
            update(a,i,val,mid+1,high,2*pos+2);
        }
        segtree[pos]=segtree[2*pos+1]+segtree[2*pos+2];
    }
}
void update1(ll i, ll val, ll low, ll high, ll pos)
{
    if(i<low || i>high)
    {
        return;
    }
    if(low==high)
    {
        segtree[pos]=val;
        return;
    }
    ll mid=(low+high)/2;
    update1(a,i,val,low,mid,2*pos+1);
    update1(a,i,val,mid+1,high,2*pos+2);
    segtree[pos]=segtree[2*pos+1]+segtree[2*pos+2];
    
}
void update2(ll l,ll r, ll diff, ll low, ll high, ll pos)
{
    if(r<low || l>high)
    {
        return;
    }
    if(low==high)
    {
        segtree[pos]+=diff;
        return;
    }
    ll mid=(low+high)/2;
    update2(a,l,r,diff,low,mid,2*pos+1);
    update2(a,l,r,diff,mid+1,high,2*pos+2);
    segtree[pos]=segtree[2*pos+1]+segtree[2*pos+2];
}
segtree.assign(4*n+1,0);
*/

/*
vector<ll>seg,lazy;
void build_segtree(vector<ll>& a, ll low, ll high, ll pos)
{
    if(low==high)
    {
        seg[pos]=a[low];
        return;
    }

    ll mid=low+(high-low)/2;
    build_segtree(a,low,mid,2*pos+1);
    build_segtree(a,mid+1,high,2*pos+2);
    seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}
void upd(ll l, ll r, ll low, ll high, ll v, ll pos)
{
    if(lazy[pos]!=0)
    {
        seg[pos]+=(high-low+1)*lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(high<l || low>r)
    {
        return;
    }
    if(high<=r && low>=l)
    {
        seg[pos]+=(high-low+1)*v;
        if(low!=high)
        {
            lazy[2*pos+1]+=v;
            lazy[2*pos+2]+=v;
        }
        return;
    }
    ll m=(low+high)/2;
    upd(l,r,low,m,v,2*pos+1);
    upd(l,r,m+1,high,v,2*pos+2);
    seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}
ll qry(ll l, ll r, ll low, ll high, ll pos)
{
    if(lazy[pos]!=0)
    {
        seg[pos]+=(high-low+1)*lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(high<l || low>r)
    {
        return 0;
    }
    if(high<=r && low>=l)
    {
        return seg[pos];
    }
    ll m=(low+high)/2;
    return qry(l,r,low,m,2*pos+1)+qry(l,r,m+1,high,2*pos+2);
}
seg.assign(4*n+1,0);
lazy.assign(4*n+1,0);
*/

/*
vector<ll>seg,lazy;
void build_segtree(vector<ll>& a, ll low, ll high, ll pos)
{
    if(low==high)
    {
        seg[pos]=a[low];
        return;
    }
    
    ll mid=low+(high-low)/2;
    build_segtree(a,low,mid,2*pos+1);
    build_segtree(a,mid+1,high,2*pos+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);

}
void upd(ll l, ll r, ll low, ll high, ll v, ll pos)
{
    if(lazy[pos]!=0)
    {
        seg[pos]+=lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(high<l || low>r)
    {
        return;
    }
    if(high<=r && low>=l)
    {
        seg[pos]+=v;
        if(low!=high)
        {
            lazy[2*pos+1]+=v;
            lazy[2*pos+2]+=v;
        }
        return;
    }
    ll m=(low+high)/2;
    upd(l,r,low,m,v,2*pos+1);
    upd(l,r,m+1,high,v,2*pos+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}
ll qry(ll l, ll r, ll low, ll high, ll pos)
{
    if(lazy[pos]!=0)
    {
        seg[pos]+=lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(high<l || low>r)
    {
        return 9e18;
    }
    if(high<=r && low>=l)
    {
        return seg[pos];
    }
    ll m=(low+high)/2;
    ll a=qry(l,r,low,m,2*pos+1);
    ll b=qry(l,r,m+1,high,2*pos+2);
    return min(a,b);
}
seg.assign(4*n+1,0);
lazy.assign(4*n+1,0);
*/

/*
const ll mx=2e5;
vector<vector<ll>>store(mx+5);
for(ll k=1;k<=mx;k++)
{
    for(ll i=k;i<=mx;i+=k)
    {
        store[i].push_back(k);
    }
}
*/

/*
vector<vector<ll>>adj;
void dfs(ll u, ll p){
    for(auto i:adj[u]){
        if(i==p) continue;
        dfs(i,u);
    }
}
*/

/*Zarr
string str;
vector<ll>z;
ll n;
void getZarr(){
    ll l,k,r;
    l=r=0;
    for(ll i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n && str[r-l]==str[r]){
                r++;
            }
            z[i]=r-l;
            r--;
        }
        else{
            k=i-l;
            if(z[k]<r-i+1){
                z[i]=z[k];
            }
            else{
                l=i;
                while(r<n && str[r-l]==str[r]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }
        }
    }
}
z.assign(n,0);
*/

/*KMP pref_suff
string needle;
vector<ll> lps;
ll m;
void KMP_pref_suff(){
    ll prev=0;
    ll i=1;
    while(i<m){
        if(needle[i]==needle[prev]){
            prev+=1;
            lps[i]=prev;
            i+=1;
        }
        else{
            if(prev==0){
                i+=1;
            }
            else{
                prev=lps[prev-1];
            }
        }
    }
}
*/
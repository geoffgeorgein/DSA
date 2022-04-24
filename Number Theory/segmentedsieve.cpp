#include<bits/stdc++.h>
using namespace std;

#define all(x)      (x).begin(),(x).end()
#define rall(x)     x.rbegin(),x.rend()
#define pb          push_back
#define ppb         pop_back
#define pf          push_front
#define ppf         pop_front
#define F           first
#define S           second
#define ll          long long
#define vi          vector<int>
#define vd          vector<double>
#define vf          vector<float>
#define vii         vector<vector<int>>
#define vll         vector<ll>
#define vlll        vector<vll> 
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define mpii        map<int,int>
#define mpll        map<ll,ll>
#define itr         ::iterator
#define setbits(x)     __builtin_popcount(x)
#define mem0(x)        memset((x), 0, sizeof((x)))
#define mem1(x)        memset((x), -1, sizeof((x)))
#define deb(x)         cout << #x << "=" << x << endl
#define deb2(x, y)     cout << #x << "=" << x << "," << #y << "=" << y << endl
#define for0(i, n)   for (int i = 0; i < (int)(n); i++)            // 0 based indexing
#define for1(i, n)   for (int i = 1; i <= (int)(n); i++)           // 1 based


const char n1='\n';
const int mod=1e9+7;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int arr[], int n)
{
    // Initialize result
    int ans = arr[0];
 

    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));
 
    return ans;
}

// Driver function to sort the vector elements
// by second element of pairs
bool sortsec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}


int powmod(int a,int n){
    int res=1;

    while(n){
        if(n%2){
            res=(res*a)%mod;
            n-=1;

        }
        else{
            a=(a*a)%mod;
            n/=2;

        }
    }
    return res;
}
vll primes;

void primesieve(int n){


    bool prime[n+1];
    memset(prime,1,n);
    prime[0]=0;prime[1]=0;
    for (int i=2;i*i<=n;i++){

        if (prime[i]==1){

            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    for(auto i=0;i<n;i++){
        if(prime[i]){
           // cout<<i<<" ";
            primes.pb(i);

        }
    }
   


}



int main(){
     #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);  
    freopen("output11.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   // cout << fixed << setprecision(9); 
   
    int t;

    cin>>t;

    primesieve(100000);

    while(t--){

        ll l,r;

        cin>>l>>r;

        if(l==1){
            l++;
        }

        ll k=r-l+1;

        vll a(k,0);

        for(ll p:primes){

                
                if(p*p<=r){
                
                
                    ll i=(l/p)*p;

                    if(i<l){
                        i+=p;
                    }

                    
                    for(;i<=r;i+=p){

                        if(i!=p){
                            a[i-l]=1;
                        }
                    }
                }
        }
        ll s=1;

        for(int i=0;i<k;i++){

            if(a[i]==0){
               // deb(l+i);
                 s*=(l+i);
                 s%=mod;
            }
        }

        cout<<s;


        cout<<n1;
    }
   


    
    

 
}

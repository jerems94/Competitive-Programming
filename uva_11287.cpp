//
// Created by sasso on 5/13/2020.
//


#include <iostream>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

ll mulmodn(ll a, ll b, ll n){
    ll res = 0;
    while(b){
        if(b & 1) res= (res+a) %n;
        a = (a*2)%n;
        b >>= 1;
    }
    return res;
}

ll powmodn(ll a, ll q, ll n){
    ll res = 1;
    while(q){
        if (q & 1) res = mulmodn(res,a,n);
        a = mulmodn(a,a,n);
        q >>= 1;
    }
    return res;
}
bool MR(ll n, int k=5){
    if(n==1 || n==4)
        return false;
    if(n==2 || n==3)
        return true;
    ll m = n - 1;
    int r = 0;
    while (m%2 == 0){
        m >>= 1;
        r+=1;
    }
    /* !!! Deterministic version for n<2^64 !!! */
//    int dtrm_set[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
//    for(ll a: dtrm_set){
//        if(a >= n) break;
    /* !!! End of deterministic version !!! */

    /* !!! Probablistic version !!! */
    while(k--){
        ll a = rand() % (n-4) + 2;
        /* !!! end of probablisitic version !!! */
        a = powmodn(a,m,n);
        if(a==1) continue;
        int i = r;
        while(i-- && a != n-1){
            a = mulmodn(a,a,n);
            if(a == 1) return false;
        }
        if(i == -1) return false;
    }
    return true;
}

int main()
{
    while(1)
    {
        ll a,p;
        cin>>p;
        cin>>a;
        if (!a && !p)
        {
            break;
        }
        bool pseudo=false;
        if(int(powmodn(a,p,p)) == a%p)
        {
            if (!MR(p)){pseudo=true;}
        }
        if(pseudo){cout<<"yes"<<endl;}
        else {cout<<"no"<<endl;}

    }

return 0;
}
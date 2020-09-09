
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <assert.h>

using namespace std;
typedef vector<unsigned long long> vul;
typedef vector<vector<unsigned long long>> vvul;
typedef pair<int, int> pii;
map<vector<int>,int> mp;
typedef long long ll;
using namespace std;
typedef vector<ll> vl;

vvul circulant_mult(vvul A, vvul B, ll mod) {

    vvul res(A.size());
    for (int i = 0; i < A.size(); i++)res[i].resize(A.size());
    for (int j = 0; j < A.size(); j++) {
        res[0][j] = 0;
        for (int k = 0; k < A.size(); k++) {
            res[0][j] += A[0][k] * B[k][j];
            res[0][j] = res[0][j] % mod;
        }
    }
    for(int i =1;i<A.size();i++){
        for(int j = 0;j<A.size();j++){
            res[i][(i+j)%A.size()] = res[0][j];
        }
    }
    return res;
}

vvul exp(vvul circulant, ll pow, ll mod)
{
    vvul result;
    bool first_one=true;
    while(pow){
        while(pow%2 != 1){
            pow/=2;
            circulant = circulant_mult(circulant,circulant, mod);
        }
        if(first_one) {
            result = circulant;
            first_one=false;
            pow /= 2;
        }
        if(!pow)return result;
        if(pow%2 != 1){ continue;}
        circulant = circulant_mult(circulant,circulant, mod);
        result = circulant_mult(result,circulant, mod);
        pow/=2;
    }
    return result;
}


vul  mod_mult(vvul A, vul B, ll mod) {
    vul res(B.size());
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            res[i] += (A[i][j] * B[j])%mod;
            res[i]%=mod;
        }
    }
    return res;
}
int main() {
    int n;
    cin>>n;
    while(n!=0){
        ll N,S,L,R,X;
        cin >>N>>S>>L>>R>>X;
        vul inputs;
        ll mod = pow(10, X);
        L %= mod;
        R %= mod;
        vvul circulant;
        circulant.resize(N);
        for(int i=0;i<N;i++){
            vul matrix(N);
            matrix[i]=1;
            matrix[(i-1+N)%N]=L;
            matrix[(i+1+N)%N]=R;
            circulant[i]=matrix;
        }
        ll it=N;
        while(it){
            int tmp;
            cin>>tmp;
            inputs.push_back(tmp%mod);
            it--;
        }

        vul res=inputs;
        if(S!=0)
        {
            circulant=exp(circulant,S,mod);
            res=mod_mult(circulant,inputs,mod);
        }
        printf("%lld",res[0]%mod);
        for(int i=1;i<res.size();i++){
            printf(" ");
            printf("%lld",res[i]%mod);
        }
        printf("\n");
        n--;
    }
    return 0;
}
//
// Created by sasso on 4/16/2020.
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
typedef long long  ll;
typedef unsigned long long  ull;
typedef vector<int> vi;
typedef pair<int, int> pii;


int main() {
    int test=0;
    cin>>test;
   // vector<ll> res;
    while (test) {
        ll result=0;
        priority_queue<ll,vector<ll>,std::greater<ll>> canvas;
        ll num_canvas;
        cin>>num_canvas;
        ll i=num_canvas;
        while(i)
        {
            ll c;
            cin>>c;
            canvas.push(c);
            i--;
        }

        while(num_canvas>1) {
            ll c1 = canvas.top();
            canvas.pop();
            ll c2 = canvas.top();
            canvas.pop();
            result+=(c1+c2);
            canvas.push(c1+c2);
            num_canvas--;
        }
        printf("%lld\n",result);
        test--;
    }

    return 0;

}


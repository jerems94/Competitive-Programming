//
// Created by sasso on 5/13/2020.
//

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

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;


using namespace std;


void dfs(const vvi& g, int s, vector<bool>& visible) {
    stack<int> q; q.push(s);
    //vector<bool> visible (g.size(),false);
    if (visible[s]==true){return;}
    visible[s]=true;
    while (!q.empty()) {
        int u = q.top(); q.pop();
        for (int v : g[u]) if (!visible[v]) {
                visible[v] = true;
                q.push(v);
            }}}



int main() {

    int translations, pairs;
    cin >> translations;
    cin>>pairs;
    vvi graph(26);
    while (translations) {
        char from, to;
        cin >> from >> to;
        graph[from - 97].push_back(to - 97);
        translations--;
    }


    while (pairs) {

        string toTranslate, translate;
        cin >> toTranslate >> translate;
        if (toTranslate.size() != translate.size()) {
            cout << "no" << endl;
            pairs--;
            continue;
        }
        bool possible=true;
        for (int i = 0; i < toTranslate.size(); i++) {

            vector<bool> visible(graph.size(),false);
            dfs(graph,toTranslate[i]-97,visible);
            if (!visible[translate[i]-97] && translate[i] != toTranslate[i] )
            {
                cout << "no" << endl;
                possible=false;
                break;
            }

        }
        if(possible)cout<<"yes"<<endl;

        pairs--;
    }
    return 0;
}




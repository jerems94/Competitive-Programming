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
#include <climits>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
map<vector<int>,int> mp;
typedef vector< vector<int> > vvi; // unweighted graph
typedef vector< vector< pair<int,int> > > vvii; // weighted graph


vvi g;
vector<bool> visible;
vector<bool> visited;
int num_visible;
void Dijkstra(const vvii& g, int s,vi& d)
{
    d[s] = 0;
    priority_queue<pii, std::vector<pii>, greater<pii>> q;
    q.push(pii (0, s));
    while (!q.empty())
    {
        pii front = q.top(); q.pop();
        int dist = front.first, u = front.second;
        if (dist > d[u]) continue;
        for (pii next : g[u])
        {
            int v = next.second, w = next.first;
            if(visible[v]==true)continue;
            if (d[u]+w < d[v])
            {
                d[v] = d[u]+w;
                q.push(pii(d[v], v));
            }
        }
    }
}
void dfs(const vvii& g, int s, int D) {

    if (D<=0)return;
    if(visible[s] == false) {
        visible[s] = true;
        if(visited[s]==false)num_visible--;
        for (pii u : g[s]) {
            visible[s] = true;
            visited[s] = true;
            dfs(g,u.second, D-u.first);
        }
    }
}

int main() {

    int N, M, A, K;
    cin >> N >> M >> A >> K;
    while (!(N == 0 && M == 0 && A == 0 && K == 0)) {
        vvii g(N);
        for (int i = 0; i < M; i++) {
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            v1--;
            v2--;
            pii edge1, edge2;
            edge1.first = w;
            edge2.first = w;
            edge1.second = v2;
            edge2.second = v1;
            g[v1].push_back(edge1);
            g[v2].push_back(edge2);
        }
        vi d = vi(g.size(),INT_MAX);
        vector<bool> initial (N,false);
        visited = initial;
        visible = visited;
        int num=0;
        for (int i = 0; i < A; i++) {
            int invaded;
            cin >> invaded;
            invaded--;
            visible[invaded]=true;
            Dijkstra(g,invaded,d);
            for(int i=0;i<d.size();i++){
                if(visited[i]==false)
                {
                        if(d[i]>=K)num++;
                    else{visited[i]=true;}
                }
            }
            cout << num <<endl;
            num=0;
        }
        cin >> N >> M >> A >> K;
        cout << endl;
    }
    return 0;
}
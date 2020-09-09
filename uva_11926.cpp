//
// Created by sasso on 4/6/2020.
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


#define N 1000001


bool pair_compare(pii& p1, pii& p2)
{
    return p1.first<p2.first;
}

int main()
{
    while(1)
    {
        int one_time_task,repetitive_tasks;
        bool possible=true;
        cin>>one_time_task>>repetitive_tasks;
        vector<pii> tasks;
        if(one_time_task==0 && repetitive_tasks==0){
            break;
        }
        while(one_time_task)
        {
            int start,end;
            cin>>start>>end;
            pii new_task={start,end};
            tasks.push_back(new_task);
            one_time_task--;
        }
        while(repetitive_tasks)
        {
            int start,end,rep;
            cin>>start>>end>>rep;
            while(end<N) {
                pii new_task = {start, end};
                tasks.push_back(new_task);
                start+=rep;
                end+=rep;
            }
            repetitive_tasks--;
        }
        sort(tasks.begin(),tasks.end(),pair_compare);
        for(int i=0;i<tasks.size()-1;i++)
        {
            if(tasks[i].second>tasks[i+1].first){possible=false;}
        }

        if(possible){cout<<"NO CONFLICT"<<endl;}
        else {cout<<"CONFLICT"<<endl;}
    }

}

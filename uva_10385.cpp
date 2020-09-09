//
// Created by sasso on 4/14/2020.
//


#include <iostream>

#include <fstream>
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

int main() {
string str;
//ifstream cin( "C:\\Users\\sasso\\Documents\\semester 6\\competitive programming\\HW1\\input.txt",ifstream::in );

    while(1) {
        getline(cin,str);
        while(str.empty())
        {
            getline(cin,str);
            if(cin.eof()){break;}
        }
        if(cin.eof()){break;}
        double distance=stod(str);
        double  participants = 1;
        cin>> participants;
        double k = participants;
        vector<pair<double, double>> velocities;
        while (k > 1) {
            pair<double, double> new_part;
            cin >> new_part.first >> new_part.second;
            velocities.push_back(new_part);
            k--;
        }
        pair<double, double> cheater;
        cin >> cheater.first >> cheater.second;
       /* bool possible=true;
        for (auto &x:velocities) {
            if ((x.first >= cheater.first && x.second >= cheater.second) && !(x.first == cheater.first && x.second == cheater.second)) {
                cout << "The cheater cannot win." << endl;
                possible=false;
                break;
            }

        }
        if(!possible){continue;}
        */
        double d = 1e-5*5.0;
        double bestDiff = 0, bestdist = -1e-5;
        while (d < distance) {
            bool goodDistance = true;
            double cheaterTime =d / cheater.first + (distance - d) / cheater.second;
            double timeDiff = 9999999;
            for (auto &x:velocities) {
                double Time = d / x.first + (distance - d) / x.second;
                if (Time < cheaterTime) {
                    goodDistance = false;
                    break;
                }
                if (Time -cheaterTime< timeDiff) { timeDiff = Time-cheaterTime; }
            }
            if (!goodDistance) {
                d+=1e-5*5.0;
                continue;
            }
            if (timeDiff > bestDiff) {
                bestDiff = timeDiff;
                bestdist = d;
            }
            d += 1e-5*5.0;
        }

        if (bestDiff > 0.00)
            printf("The cheater can win by %d seconds with r = %.2lfkm and k = %.2lfkm.\n",(int)(rint(3600.0*bestDiff)),fabs(bestdist),fabs((double)distance-bestdist));
        else
            printf("The cheater cannot win.\n");
    }
    return 0;
}


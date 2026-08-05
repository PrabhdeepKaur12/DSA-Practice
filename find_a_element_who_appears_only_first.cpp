#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {4, 5, 1, 2, 0, 4, 1, 2};

    unordered_map<int, int> mp;

    for(int x : nums) {
        mp[x]++;
    }

    for(int x : nums) {
        if(mp[x] == 1) {
            cout << x;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
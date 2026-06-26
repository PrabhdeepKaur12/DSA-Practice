class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();

        queue<int> radiant, dire;

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front();
            int d = dire.front();

            radiant.pop();
            dire.pop();

            if (r < d) {
                // Radiant senator acts first, bans Dire senator
                radiant.push(r + n);
            } else {
                // Dire senator acts first, bans Radiant senator
                dire.push(d + n);
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};
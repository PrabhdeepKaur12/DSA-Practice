class Solution {
public:
    vector<vector<int>> dist;
    int n;

    bool canReach(vector<vector<int>>& d, int safe) {
        if (d[0][0] < safe) return false;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        q.push({0, 0});
        vis[0][0] = 1;

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n - 1 && y == n - 1) {
                return true;
            }

            for (auto &p : dir) {
                int nx = x + p[0];
                int ny = y + p[1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    !vis[nx][ny] && d[nx][ny] >= safe) {

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        dist.assign(n, vector<int>(n, 1e9));

        queue<pair<int,int>> q;

        // Multi-source BFS from thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto &p : dir) {
                int nx = x + p[0];
                int ny = y + p[1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    dist[nx][ny] > dist[x][y] + 1) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        int low = 0, high = 2 * n, ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (canReach(dist, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
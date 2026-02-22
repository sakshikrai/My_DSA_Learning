// problem link- https://leetcode.com/problems/pacific-atlantic-water-flow/description/?envType=daily-question&envId=2025-10-05

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific_reachable(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic_reachable(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            dfs(i, 0, heights, pacific_reachable);
        }
        for (int j = 1; j < n; ++j) {
            dfs(0, j, heights, pacific_reachable);
        }

        for (int i = 0; i < m; ++i) {
            dfs(i, n - 1, heights, atlantic_reachable);
        }
        for (int j = 0; j < n - 1; ++j) {
            dfs(m - 1, j, heights, atlantic_reachable);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific_reachable[i][j] && atlantic_reachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void dfs(int r, int c, const vector<vector<int>>& heights, vector<vector<bool>>& reachable) {
        reachable[r][c] = true;
        int m = heights.size();
        int n = heights[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !reachable[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, reachable);
            }
        }
    }
};
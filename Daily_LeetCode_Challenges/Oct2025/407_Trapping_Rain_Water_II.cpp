// problem link: https://leetcode.com/problems/trapping-rain-water-ii/submissions/1789884316/?envType=daily-question&envId=2025-10-03

const int dir[5] = {0, 1, 0, -1, 0};
unsigned boundary[40000];
class Solution {
public:
    static unsigned pack(unsigned h, unsigned i, unsigned j) {
        return (h << 16) | (i << 8) | j;
    }

    static array<int, 3> unpack(unsigned info) {
        array<int, 3> ans;
        ans[0] = info >> 16, ans[1] = (info >> 8) & 255, ans[2] = info & 255;
        return ans;
    }

    static int trapRainWater(vector<vector<int>>& height) {
        const int m = height.size(), n = height[0].size();
        if (m <= 2 || n <= 2)
            return 0; // No trapped water possible

        // Add boundary cells  mark  visited
        int N = 0;
        for (int i = 0; i < m; i++) {
            boundary[N++] = pack(height[i][0], i, 0);
            boundary[N++] = pack(height[i][n - 1], i, n - 1);
            height[i][0] = height[i][n - 1] = -1; // visited
        }

        for (int j = 1; j < n - 1; j++) {
            boundary[N++] = pack(height[0][j], 0, j);
            boundary[N++] = pack(height[m - 1][j], m - 1, j);
            height[0][j] = height[m - 1][j] = -1; // visited
        }

        // Build a min-heap
        make_heap(boundary, boundary + N, greater<>());

        int ans = 0, water_level = 0;

        while (N > 0) {
            // Extract the smallest element from the heap
            pop_heap(boundary, boundary + N, greater<>());
            unsigned info = boundary[N - 1];
            N--;

            auto [h, i, j] = unpack(info);
            water_level = max(water_level, h);

            // Process adjacent cell
            for (int k = 0; k < 4; k++) {
                int i0 = i + dir[k], j0 = j + dir[k + 1];
                if (i0 < 0 || i0 >= m || j0 < 0 || j0 >= n ||
                    height[i0][j0] == -1)
                    continue;

                int currH = height[i0][j0];
                if (currH < water_level)
                    ans += water_level - currH;
                //    cout<<"water_level="<<water_level<<" currH="<<currH<<"
                //    i0="<<i0<<" j0="<<j0<<" ans="<<ans<<endl;
                // Mark the cell as visited and push it to the heap
                height[i0][j0] = -1;
                boundary[N++] = pack(currH, i0, j0);
                push_heap(boundary, boundary + N, greater<>());
            }
        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
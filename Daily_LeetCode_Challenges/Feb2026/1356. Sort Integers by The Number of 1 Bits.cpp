class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, multiset<int>> bitmap;
        for(int val : arr) {
            int bits = __builtin_popcount(val);
            bitmap[bits].insert(val);
        }
        
        vector<int> ans;
        for(auto p : bitmap) {
            for(int val : p.second) {
                ans.push_back(val);
            }
        } 
        return ans;
    }
};
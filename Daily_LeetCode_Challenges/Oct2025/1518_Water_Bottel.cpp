// problrm link- https://leetcode.com/problems/water-bottles/submissions/1787994769/?envType=daily-question&envId=2025-10-01


class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            int newBottles = emptyBottles / numExchange;
            int remainingEmpty = emptyBottles % numExchange;
            
            totalDrunk += newBottles;
            
            emptyBottles = newBottles + remainingEmpty;
        }
        
        return totalDrunk;
    }
};
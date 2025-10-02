
//problem link:https://leetcode.com/problems/water-bottles-ii/?envType=daily-question&envId=2025-10-02
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
    
        int bD = numBottles;
        
        
        int eB = numBottles;
        
        while (eB >= numExchange) {
        
            eB -= numExchange;
            
        
            numExchange++;
            
            
            bD++;
            
           
            eB++;
        }
        
        return bD;
    }
};
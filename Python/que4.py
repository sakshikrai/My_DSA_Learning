# problem link-https://leetcode.com/problems/remove-element/?envType=problem-list-v2&envId=array

class Solution(object):
    def removeElement(self, nums, val):
        if not nums:
            return 0
        
        k=0
        for i in range(0,len(nums)):
            if nums[i]!=val:
                nums[k]=nums[i]
                k+=1
        return k
        
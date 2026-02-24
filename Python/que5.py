# problem link-https://leetcode.com/problems/search-insert-position/?envType=problem-list-v2&envId=array

# Linear Search
# Time complexity- O(n)

class Solution(object):
    def searchInsert(self, nums, target):
        if not nums:
            return 0
        for i in range(0,len(nums)):
            if nums[i]>=target:
                return i
        return len(nums)
    

        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

# Binary Search
# Time complexity- O(log n)

class Solution(object):
    def searchInsert(self, nums, target):
        l=0
        r=len(nums)-1
        while l<=r:
            mid = (l+r)//2
            if nums[mid]==target:
                return mid
            elif nums[mid]<target:
                l=mid+1

            else:
                r=mid-1
        return l


        
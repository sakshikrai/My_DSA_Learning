# problem link -https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=problem-list-v2&envId=array
class Solution(object):
    def removeDuplicates(self, nums):
        if not nums:
            return ""

        k =1
        for i in range(1, len(nums)):
            if nums[i]!=nums[i-1]:
                nums[k]=nums[i]
                k+=1

        return k
        """
        :type nums: List[int]
        :rtype: int
        """
        
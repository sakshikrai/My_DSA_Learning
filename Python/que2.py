# problem link- https://leetcode.com/problems/longest-common-prefix/?envType=problem-list-v2&envId=array

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return " "
        p=strs[0]
        for i in range(1,len(strs)):
            a=strs[i]
            while not a.startswith(p):
                p=p[:-1]
            if not p:
                return ""
        return p
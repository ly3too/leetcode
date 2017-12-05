class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums) - 1;
        m = n;
        if n < 1:
            return

        while n > 0:
            if nums[n-1] < nums[n]:
                break;
            n -= 1;
        n -= 1;

        if n < 0:
            nums.sort();
            return

        while m > 0:
            if nums[m] > nums[n]:
                break
            m -= 1;

        nums[m], nums[n] = nums[n], nums[m];

        n += 1;
        nums[n:] = sorted(nums[n:]);


if __name__ == '__main__':
    input = [1,3,2];
    Solution().nextPermutation(input)
    print(input);

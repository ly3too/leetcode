

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort();

        result = [];

        indx = 0;
        while indx + 2 < len(nums):
            if nums[indx] > 0:
                break

            front = indx + 1;
            back = len(nums) - 1;
            tmp = -nums[indx];
            while front < back:
                x = nums[front];
                y = nums[back];

                if  x + y < tmp:
                    front = front + 1;
                elif x + y > tmp:
                    back = back - 1;
                else :
                    # find one result
                    result.append([nums[indx], x, y]);
                    while nums[front] == x and front < back:
                        front = front + 1

            while indx + 2 < len(nums):
                indx += 1;
                if not(nums[indx] == nums[indx-1]):
                    break;

        return result;


if __name__ == '__main__':
    input = [-1, -1, 0, 1, 1];
    print(Solution().threeSum(input))

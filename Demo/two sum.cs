using System;

public class Solution
{

    int i = 0;

    public int[] TwoSum(int[] nums, int target)
    {
        Dictionary<int, int> temp = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++)
        {
            int left = target - nums[i];
            if (temp.ContainsKey(left))
            {
                return new int[] { temp[left], i };
            }
            if (!temp.ContainsKey(nums[i]))
            {
                temp.Add(nums[i], i);
            }
        }
        return null;
    }

    public Main()
    {
        int[] nums = new int[2, 7, 11, 15];

        target = 9;

        TwoSum(nums, target);

        console.writeline("[", i, ",", i + 1, "]");
    }

}

// Time Limit Exceeded, O(n^2)
int minSubArrayLen(int target, int *nums, int numsSize)
{
    int minLen = 0x7fffffff;
    for (int i = 0; i < numsSize; i++)
    {
        int sum = 0;
        for (int j = i; j < numsSize; j++)
        {
            sum += nums[j];
            if (sum >= target && j - i + 1 < minLen)
            {
                minLen = j - i + 1;
                break;
            }
        }
    }
    return minLen == 0x7fffffff ? 0 : minLen;
}
// O(n) solution using sliding window
int minSubArrayLen(int target, int *nums, int numsSize)
{
    int minLen = 0x7fffffff;
    int sum = 0;
    int left = 0;

    for (int right = 0; right < numsSize; right++)
    {
        sum += nums[right]; // 扩大窗口
        // 当窗口的和大于等于目标时，尝试缩小窗口
        while (sum >= target)
        {
            minLen = (right - left + 1) < minLen ? (right - left + 1) : minLen; // 更新最小长度
            sum -= nums[left];                                                  // 缩小窗口
            left++;
        }
    }

    return minLen == 0x7fffffff ? 0 : minLen; // 如果没有找到符合条件的子数组，返回 0
}
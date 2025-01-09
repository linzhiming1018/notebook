// My Implementation
int removeElement1(int *nums, int numsSize, int val)
{
    int i = 0, j = numsSize - 1;
    int count = 0;
    while (i <= j)
    {
        while (i <= j && nums[i] != val)
        {
            count++;
            i++;
        }
        while (i <= j && nums[j] == val)
        {
            j--;
        }
        if (i <= j)
        {
            nums[i] = nums[j];
            nums[j] = val;
        }
    }
    return count;
}

// Solution
int removeElement2(int *nums, int numsSize, int val)
{
    int slowIndex = 0; // 慢指针指向新数组需要更新的位置
    // 快指针获取新数组所需的元素
    for (int fastIndex = 0; fastIndex < numsSize; fastIndex++)
    {
        if (nums[fastIndex] != val)
        {
            nums[slowIndex++] = nums[fastIndex];
        }
    }
    return slowIndex;
}

// Brute Force, Time Limit Exceeded
int removeElement3(int *nums, int numsSize, int val)
{
    int size = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == val)
        {
            for (int j = i; j < numsSize - 1; j++)
            {
                nums[j] = nums[j + 1];
            }
            i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
            size--;
        }
    }
    return size;
}

int main()
{
    int nums[] = {2};
    removeElement1(nums, sizeof(nums) / sizeof(nums[0]), 3);
    return 0;
}
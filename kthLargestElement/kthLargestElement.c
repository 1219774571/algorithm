/*
 * 找第k打的元素
 * 使用快速排序方法
 * 使用快速排序赋值
 * 取标点n
 * 如 left <= right
 * 就：
 * 取left对比看有没有n大的值
 * 取right对比看有没有比n小的值
 * 然后互换他们对应的值
 * 判断 n - 1的值是否等于左边递增点。
 * 是的话需要找的值就是这个了。
 * 不是的话看大于还是小于
 * 大于就找左边，同时再次排序。
 * 小于就找右边，同时再次排序。直到完成等于。
 * */

int quickSort(int nums[],int left, int right, int k)
{
	int i = left;//左
        int j = right;//右
        int tmp = nums[i];//取标点
        while(i<j)
        {
            while(i<j && tmp>=nums[j])//从右边找小于标点值
                j--;
            if(i<j)
            {
                nums[i]=nums[j];//从右边换到左边
                i++;
            }
            while(i<j && tmp<nums[i])//从左边找大于标点值
                i++;
            if(i<j)
            {
                nums[j]=nums[i];//从左边换到右边
                j--;
            }

        }
        nums[i] = tmp;
        if(i == k -1)//找到了值
        {
            return tmp;
        }
        else if(i < k-1)//没有找到，i太小，需要找的值在右边
        {
            return quickSort(nums,i+1,right,k);
        }
        else//没有找到，i太大，需要找的值在左边
        {
            return quickSort(nums,left,i-1,k);
        }
}
int kthLargestElement(int n, int nums[],int size)
{
	return quickSort(nums, 0, size-1, n);
}

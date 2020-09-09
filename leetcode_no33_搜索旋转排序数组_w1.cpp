/*------------------------------------------------------------------|
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	二分查找法
*	
*	执行用时：4 ms, 在所有 C++ 提交中击败了71.73%的用户
*	内存消耗：11.2 MB, 在所有 C++ 提交中击败了24.42%的用户
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

int search(vector<int>& nums, int target) 
{
	int len = nums.size();
	
	if (len == 0)
	{
		return -1;
	}
	if (len == 1)
	{
		return target == nums[0] ? 0 : -1;
	}
	int head = 0;
	int tail = len - 1;

	while (head <= tail)
	{
		int mid = (head + tail) / 2;

		if (nums[mid] == target)
		{
			return mid;
		}

		if (nums[0] <= nums[mid])
		{
			if (target >= nums[0] && target < nums[mid])
			{
				tail = mid - 1;
			}
			else
			{
				head = mid + 1;
			}
		}
		else
		{
			if (target > nums[mid] && target <= nums[tail])
			{
				head = mid + 1;
			}
			else
			{
				tail = mid - 1;
			}
		}
	}
	return -1;


}

int main()
{
	vector<int> nums = { 4,5,6,7,0,1,2 };
	int target = 5;
}
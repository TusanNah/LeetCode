//Given an integer array nums, find the
//subarray
//with the largest sum, and return its sum.
//
//
//
//Example 1:
//
//Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//Output : 6
//Explanation : The subarray[4, -1, 2, 1] has the largest sum 6.
//
//Example 2 :
//
//	Input : nums = [1]
//	Output : 1
//	Explanation : The subarray[1] has the largest sum 1.
//
//	Example 3 :
//
//	Input : nums = [5, 4, -1, 7, 8]
//	Output : 23
//	Explanation : The subarray[5, 4, -1, 7, 8] has the largest sum 23.

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxCurrent = nums[0], maxGlobal = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			maxCurrent = max(nums[i], maxCurrent + nums[i]);
			if (maxCurrent > maxGlobal) {
				maxGlobal = maxCurrent;
			}
		}
		return maxGlobal;
	}
};

//Solution: Kandane's Algorithm, use maxCurrent and maxGlobal then iterate each element in array


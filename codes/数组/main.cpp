// Copyright (c) cbb9556. 2024-2024. All rights reserved.

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size(); // 定义target在左闭右开的区间里，即：[left, right)
        while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle; // target 在左区间，在[left, middle)中
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，在[middle + 1, right)中
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }
};

int main() {
    int target;
    vector<int> nums;
    int len;
    while (true) {
        cin >> target;
        cin >> len;
        for (int i = 0; i < len; ++i) {
            int num;
            cin >> num;
            nums.push_back(num);
        }
        Solution s1;
        cout << s1.search(nums, target) << endl;
        nums.clear();
    }
}
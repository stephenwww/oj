// Copyright 2017 Qi Wang
// Date: 2017-11-08
// Case 1: []
// Case 2: [10]
// Case 3: [1, 2, 3]
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    if (nums.empty()) return {};
    if (nums.size() == 1) return {1};
    vector<int> result(nums.size(), 1);
    for (int i = result.size() - 2; i >= 0; --i) {
      result[i] = result[i + 1] * nums[i + 1];
    }
    for (int i = 1, val = 1; i < result.size(); ++i) {
      result[i] *= (val *= nums[i - 1]);
    }
    return result;
  }
};

// Date: 2017-07-25
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    if (nums.empty()) return {};
    vector<int> result(nums.size());
    for (int i = 0, acc = 1; i < nums.size(); ++i) {
      result[i] = acc;
      acc *= nums[i];
    }
    for (int i = nums.size() - 1, acc = 1; i >= 0; --i) {
      result[i] *= acc;
      acc *= nums[i];
    }
    return result;
  }
};

// Date: 2017-02-18
// Note that the solution presented on 2016-11-26 is better
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    // init left
    vector<int> left(n);
    left.front() = nums.front();
    for (int i = 1; i < n; ++i)
      left[i] = nums[i] * left[i - 1];
    // init right
    vector<int> right(nums.size(), 1);
    right.back() = nums.back();
    for (int i = n - 2; i >= 0; --i)
      right[i] = nums[i] * right[i + 1];
    // calculate the result
    vector<int> result(n);
    result.front() = right[1];
    result.back() = left[n - 2];
    for (int i = 1; i < n - 1; ++i)
      result[i] = left[i - 1] * right[i + 1];
    return result;
  }
};

// Date: 2016-11-26
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 1);
    for (int i = 1, left = 1; i < static_cast<int>(nums.size()); ++i) {
      left *= nums[i - 1];
      res[i] *= left;
    }
    for (int i = static_cast<int>(nums.size()) - 2, right = 1; i >= 0; --i) {
      right *= nums[i + 1];
      res[i] *= right;
    }
    return res;
  }
};

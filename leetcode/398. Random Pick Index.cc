// Copyright 2017 Qi Wang
// Date: 2017-07-30
class Solution {
 public:
  Solution(vector<int> nums) : nums_(nums) {}
  
  int pick(int target) {
    int result = -1;
    for (int i = 0, cnt = 0; i < nums_.size(); ++i) {
      if (nums_[i] != target) {
        continue;
      }
      // This probablity implementation is refer to the solution on 2016-11-27
      if (rand() % ++cnt == 0) {
        result = i;
      }
    }
    return result;
  }

 private:
  vector<int> nums_;
};

// Date: 2017-07-30
class Solution {
 public:
  Solution(vector<int> nums) {
    for (int i = 0; i < nums.size(); ++i) {
      num_to_idxs_map_[nums[i]].push_back(i);
    }
  }
  
  int pick(int target) {
    auto& p = num_to_idxs_map_[target];
    return p[rand() % p.size()];
  }

 private:
  unordered_map<int, vector<int>> num_to_idxs_map_;
};

// Date: 2017-07-30
// MLE
class Solution {
 public:
  Solution(vector<int> nums) {
    for (int i = 0; i < nums.size(); ++i) {
      num_to_idxs_map_[nums[i]].push_back(i);
    }
  }
  
  int pick(int target) {
    auto& p = num_to_idxs_map_[target];
    return p[rand() % p.size()];
  }

 private:
  unordered_map<int, vector<int>> num_to_idxs_map_;
};

// Method 1
// Reservoir sampling
// Time: somethings TLE, sometimes beats 88% cpp solutions with about 110ms
// Refer to: http://www.cnblogs.com/grandyang/p/5875509.html
// Date: 2016-11-27
class Solution {
 public:
  Solution(vector<int> nums) : nums_(move(nums)) {}
    
  int pick(int target) {
    int res = -1;
    for (size_t i = 0, cnt = 0; i < nums_.size(); ++i) {
      if (nums_[i] != target) continue;
      ++cnt;
      if (rand() % cnt == 0) res = i;
    }
    return res;
  }

 private:
  vector<int> nums_;
};

// Method 1
// Time: somethings 130ms, sometimes 218ms : P
// Date: 2016-11-26
class Solution {
 public:
  Solution(vector<int> nums) : nums_(move(nums)) {}
    
  int pick(int target) {
    vector<int> idxs;
    for (size_t i = 0; i < nums_.size(); ++i)
      if (nums_[i] == target) idxs.push_back(i);
    return idxs[rand() % idxs.size()];
  }

 private:
  vector<int> nums_;
};
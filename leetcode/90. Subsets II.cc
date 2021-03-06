// Copyright 2017 Qi Wang
// Date: 2017-10-25
// Case 1: [1, 1, 2]
class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> cur;
    vector<vector<int>> result;
    Subset(nums, 0, &cur, &result);
    return result;
  }

 private:
  void Subset(const vector<int>& nums, int idx, vector<int>* cur,
      vector<vector<int>>* result) const {
    if (idx == nums.size()) {
      result->push_back(*cur);
    } else {
      int cnt = 1;
      while (idx + cnt < nums.size() &&
             nums[idx + cnt] == nums[idx + cnt - 1]) {
        ++cnt;
      }
      Subset(nums, idx + cnt, cur, result);
      for (int i = 0; i < cnt; ++i) {
        cur->push_back(nums[idx]);
        Subset(nums, idx + cnt, cur, result);
      }
      while (cnt--) {
        cur->pop_back();
      }
    }
  }
};

// Date: 2017-08-15
class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> cur;
    F(nums, 0, &cur, &result);
    return result;
  }

 private:
  void F(const vector<int>& nums, int idx, vector<int>* cur,
      vector<vector<int>>* result) const {
    if (idx == nums.size()) {
      result->push_back(*cur);
    } else {
      int len = 1;
      for (; idx + len != nums.size() && nums[idx] == nums[idx + len];
          ++len) {}
      F(nums, idx + len, cur, result);
      for (int i = 0; i < len; ++i) {
        cur->push_back(nums[idx + i]);
        F(nums, idx + len, cur, result);
      }
      while (len--) {
        cur->pop_back();
      }
    }
  }
};

// Date: 2017-07-25
class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> cur;
    F(nums, 0, cur, &result);
    return result;
  }

 private:
  void F(vector<int>& nums, int idx, vector<int>& cur,
      vector<vector<int>>* result) {
    if (idx == nums.size()) {
      result->push_back(cur);
      return;
    }
    int len = 1;
    for (; idx + len < nums.size() && nums[idx + len] == nums[idx];
        ++len) {}
    F(nums, idx + len, cur, result);
    for (int i = 0; i < len; ++i) {
      cur.push_back(nums[idx]);
      F(nums, idx + len, cur, result);
    }
    for (int i = 0; i < len; ++i) {
      cur.pop_back();
    }
  }
};

class Solution
{
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) 
    {
      if (S.empty())
      {
        return vector<vector<int>>();
      }

      sort(S.begin(), S.end());
      num.push_back(S.front());
      cnt.push_back(1);
      for (size_t i = 1; i < S.size(); ++ i)
      {
        if (S[i] != S[i-1])
        {
          num.push_back(S[i]);
          cnt.push_back(1);
        } else
        {
          ++ cnt.back();
        }
      }
      vector<int> now;
      for (size_t i = 0; i <= S.size(); ++ i)
      {
        gao(now, 0, i);
      }

      return ret;
    }
private:
  vector<int> num;
  vector<int> cnt;
  vector<vector<int>> ret;
  void gao(vector<int>& now, size_t index, size_t bound)
  {
    if (now.size() == bound)
    {
      ret.push_back(now);
      return ;
    }
    for (size_t i = index; i < num.size(); ++ i)
    {
      int j = 0;
      for (; j<cnt[i] && now.size()<bound; ++ j)
      {
        now.push_back(num[i]);
        gao(now, i+1, bound);
      }
      while (j --)
      {
        now.pop_back();
      }
    }
  }
};
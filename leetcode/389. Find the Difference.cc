// Copyright 2016 Qi Wang
// Method 2: bit manipulation
// This method is probably slower than the one using counters,
// 'cause the XOR operation is harmful to the pipeline
// Date: 2016-12-17
class Solution {
 public:
  char findTheDifference(string s, string t) {
    char res = 0;
    for (char c : s) res ^= c;
    for (char c : t) res ^= c;
    return res;
  }
};

// Date: 2016-10-02
class Solution {
 public:
  char findTheDifference(string s, string t) {
    vector<int> sCnt(26, 0), tCnt(26, 0);
    for (size_t i = 0; i < s.size(); ++i) {
      ++sCnt[s[i] - 'a'];
      ++tCnt[t[i] - 'a'];
    }
    ++tCnt[t.back() - 'a'];
    for (size_t i = 0; i < 26; ++i)
      if (tCnt[i] > sCnt[i])
        return i + 'a';
    return -1;  // soft the compiler
  }
};

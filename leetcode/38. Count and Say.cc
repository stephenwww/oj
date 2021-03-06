// Copyright 2017 Qi Wang
// Date: 2017-11-08
class Solution {
 public:
  string countAndSay(int n) {
    if (n < 1) return "";
    string result = "1";
    for (int i = 1; i < n; ++i) {
      result = CountAndSay(result);
    }
    return result;
  }
 
 private:
  string CountAndSay(const string& s) const {
    string result;
    int cnt = 1;
    char prev_c = s.front();
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == prev_c) {
        ++cnt;
      } else {
        result += to_string(cnt) + prev_c;
        cnt = 1;
        prev_c = s[i];
      }
    }
    return result + to_string(cnt) + prev_c;
  }
};
 
// Date: 2017-08-16
class Solution {
 public:
  string countAndSay(int n) {
    if (n <= 0) return "n <= 0";
    string s = "1";
    for (--n; n > 0; --n) {
      string next_s;
      cout << s << endl;
      for (int i = 0; i < s.size();) {
        int cnt = 1;
        for (; i + cnt < s.size() && s[i + cnt] == s[i]; ++cnt) {}
        next_s += to_string(cnt) + s[i];
        i += cnt;
      }
      s = move(next_s);
    }
    return s;
  }
};
 
// Date: 2017-07-25
class Solution {
 public:
  string countAndSay(int n) {
    return CountAndSay("1", n);
  }

 private:
  string CountAndSay(const string& str, int n) const {
    if (n == 1) {
      return str;
    }
    string cur;
    for (int pos = 0; pos < str.size();) {
      int len = 1;
      while (pos + len < str.size() && str[pos + len] == str[pos]) {
        ++len;
      }
      cur += to_string(len) + str[pos];
      pos += len;
    }
    return CountAndSay(cur, --n);
  }
};

class Solution 
{
public:
  string countAndSay(int n) 
  {
    string num("1"), next_num;
    
    for (int i = 1; i < n; ++ i)
    {
      int cnt = '0', last = num[0];
      next_num.clear();
      for (size_t j = 0; j < num.size(); ++ j)
      {
        if (num[j] == last)
        {
          ++ cnt;
        } else
        {
          next_num += cnt;
          next_num += last;
          cnt = '1';
          last = num[j];
        }
      }
      next_num += cnt;
      next_num += last;
      num = next_num;
    }

    return num;
  }
};

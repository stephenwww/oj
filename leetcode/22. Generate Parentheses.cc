// Copyright 2017 Qi Wang
// Date: 2017-09-13
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string cur;
    F(n, n, 0, &cur, &result);
    return result;
  }

 private:
  void F(int open, int close, int acc, string* cur,
         vector<string>* result) {
    if (open == 0 && close == 0) {
      result->push_back(*cur);
    }
    if (close > 0 && acc > 0) {
      cur->push_back(')');
      F(open, close - 1, acc - 1, cur, result);
      cur->pop_back();
    }
    if (open > 0) {
      cur->push_back('(');
      F(open - 1, close, acc + 1, cur, result);
      cur->pop_back();
    }
  }
};

// Date: 2016-12-21
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    auto res = generateParenthesis(n, n);
    for (auto& str : res) reverse(str.begin(), str.end());
    return res;
  }

 private:
  // open parenthesis remain, close parenthisis remain
  vector<string> generateParenthesis(int oRemain, int cRemain) {
    if (oRemain == 0 && cRemain == 0) {
      return vector<string>();
    // equal and non-zero
    } else if (oRemain == cRemain) {
      auto res = generateParenthesis(oRemain - 1, cRemain);
      for (auto& str : res) str += '(';
      return res;
    // oRemain < cRemain
    } else if (oRemain > 0) {
      auto res = generateParenthesis(oRemain - 1, cRemain);
      for (auto& str : res) str += '(';
      auto temp = generateParenthesis(oRemain, cRemain - 1);
      for (auto& str : temp) {
        str += ')';
        res.push_back(move(str));
      }
      return res;
    // oRemain == 0
    } else {
      return vector<string>(1, string(cRemain, ')'));
    }
  }
};

// Date: 2014-06
class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
      vector<string> ret;
        gao(0, 2*n, 0, 0, string(), ret);
        return ret;
    }
private:
  void gao(int dep, int max_dep, int left_now, int left_tot, string s, vector<string>& ret)
  {
    if (left_tot*2 > max_dep)
    {
      return ;
    } else if (dep == max_dep)
    {
      ret.push_back(s);
      return ;
    }

    gao(dep+1, max_dep, left_now+1, left_tot+1, s+'(', ret);
    if (left_now > 0)
    {
      gao(dep+1, max_dep, left_now-1, left_tot, s+')', ret);
    }
  }
};

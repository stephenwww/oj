// Copyright 2017 Qi Wang
// Date: 2017-08-07
// Refer to the previous solution
class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    int cnts[26];
    memset(cnts, 0, sizeof cnts);
    for (char task : tasks)
      ++cnts[task - 'A'];
    priority_queue<int> pq;
    for (int cnt : cnts)
      if (cnt > 0)
        pq.push(cnt);
    int result = 0;
    n += 1;
    while (!pq.empty()) {
      int time = 0;
      vector<int> temp;
      for (int i = 0; i < n && !pq.empty(); ++i) {
        ++time;
        if (pq.top() > 1) temp.push_back(pq.top() - 1);
        pq.pop();
      }
      for (int cnt : temp) pq.push(cnt);
      result += pq.empty() ? time : n;
    }
    return result;
  }
};

// Date: 2017-06-19
// Refer to: https://discuss.leetcode.com/topic/92873/c-java-clean-code-priority-queue
class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    int cnts[26];
    memset(cnts, 0, sizeof cnts);
    for (char c : tasks)
      ++cnts[c - 'A'];
    priority_queue<int> q;
    for (int cnt : cnts)
      if (cnt > 0)
        q.push(cnt);
    int cycle = n + 1;
    int result = 0;
    while (!q.empty()) {
      vector<int> temp;
      int cnt = 0;
      for (int i = 0; i < cycle && !q.empty(); ++i) {
        ++cnt;
        if (q.top() > 1)
          temp.push_back(q.top() - 1);
        q.pop();
      }
      for (int t : temp)
        q.push(t);
      result += q.empty() ? cnt : cycle;
    }
    return result;
  }
};

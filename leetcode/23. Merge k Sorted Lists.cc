// Copyright 2017 Qi Wang
// Date: 2017-11-05
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    list<ListNode*> result(lists.begin(), lists.end());
    while (result.size() > 1) {
      auto first = result.front(); result.pop_front();
      auto second = result.front(); result.pop_front();
      result.push_back(Merge(first, second));
    }
    return result.front();
  }
 
 private:
  ListNode* Merge(ListNode* lhs, ListNode* rhs) const {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (lhs != nullptr && rhs != nullptr) {
      if (lhs->val < rhs->val) {
        tail->next = lhs;
        lhs = lhs->next;
      } else {
        tail->next = rhs;
        rhs = rhs->next;
      }
      tail = tail->next;
    }
    tail->next = lhs != nullptr ? lhs : rhs;
    return dummy.next;
  }
};

// Date: 2017-10-30
// MicroStrategy 3rd round interview

// Assume n nodes per list, N * K nodes
// Returns a single sorted linked list
// Method 1: O(N * K^2)
// Method 2: divide and conquer
//   N lists -> N / 2 lists -> N /4 lists -> ... -> 1 list
//   NK * log(K)
// Method 3: priority_queue, NK * log(K)
struct ListNode {
  int val;
  ListNode* next = nullptr;
};

// Case 1: []
// Case 2: [[nullptr], [1]]
// Case 3: [[1, 2], [2, 3], [4]]
//   - Merge([1, 2], [2, 3]), return [1, 2, 2, 3], list table = [[1, 2, 2, 3], [4]]
//   ...
inline ListNode* SortKLists(list<ListNode*> lists) {
  if (lists.empty()) return nullptr;
  while (lists.size() > 1) {
    auto first = lists.front(); lists.pop_front();
    auto second = lists.front(); lists.pop_front();
    lists.push_back(MergeLists(first, second));
  }
  return lists.front();
}

// Merge([1, 2], [2, 3])
//   -> result = [dummy, 1], lhs = [2], rhs =[2, 3]
//   -> result = [dummy, 1, 2], lhs = [2], rhs = [3]
//   -> reuslt = [dummy, 1, 2, 2], lhs = [], rhs = [3]
//   -> result = [dummy, 1, 2, 2, 3]
inline ListNode* MergeLists(ListNode* lhs, ListNode* rhs) {
  if (lhs == nullptr || rhs == nullptr) {
    return lhs != nullptr ? lhs : rhs;
  }
  ListNode dummy;
  auto* tail = &dummy;
  while (lhs != nullptr && rhs != nullptr) {
    if (lhs->val < rhs->val) {
      tail->next = lhs;
      lhs = lhs->next;
    } else {
      tail->next = rhs;
      rhs = rhs->next;
    }
    tail = head->next;
  }
  tail->next = lhs != nullptr ? lhs : rhs;
  return dummy.next;
}


// Date: 2017-07-27
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {  
    priority_queue<ListNode*, vector<ListNode*>, comp> pq;
    for (ListNode* elem : lists) {
      if (elem != nullptr) {
        pq.push(elem);
      }
    }
    ListNode dummy(0);
    ListNode* cur = &dummy;
    while (!pq.empty()) {
      auto elem = pq.top(); pq.pop();
      cur->next = elem;
      cur = cur->next;
      if (elem->next != nullptr) {
        pq.push(elem->next);
      }
    }
    return dummy.next;
  }

 private:
  struct comp {
    bool operator ()(const ListNode* lhs, const ListNode* rhs) {
      return lhs->val > rhs->val;
    }
  };
};

// Date: 2017-07-03
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
      return nullptr;
    } else if (lists.size() == 1) {
      return lists.front();
    } else {
      vector<ListNode*> next;
      for (size_t i = 0; i + 1 < lists.size(); i += 2)
        next.push_back(Merge(lists[i], lists[i + 1]));
      if (lists.size() & 1) next.push_back(lists.back());
      return mergeKLists(next);
    }
  }
 
 private:
  ListNode* Merge(ListNode* a, ListNode* b) const {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    while (nullptr != a && nullptr != b)
      Advance(cur, a->val < b->val ? a : b);
    cur->next = nullptr != a ? a : b;
    return dummy.next;
  }
 
  void Advance(ListNode*& cur, ListNode*& node) const {
    cur->next = node;
    cur = node;
    node = node->next;
  }
};

// Date: 2016-12-21
// Last modified: 2017-01-03
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    if (lists.size() == 1) return lists.front();
    vector<ListNode*> next;
    for (size_t i = 0; i + 1 < lists.size(); i += 2)
      next.push_back(merge(lists[i], lists[i + 1]));
    // use & 1, on 2017-01-03
    if (lists.size() & 1) next.push_back(lists.back());
    return mergeKLists(next);
  }

 private:
  ListNode* merge(ListNode *a, ListNode *b) {
    // Unlike solution on 2016-11-19, We don't introduce shared_ptr
    ListNode dummy(0);
    ListNode *tail = &dummy;
    for (; a != nullptr && b != nullptr; tail = tail->next) {
      if (a->val < b->val) {
        tail->next = a;
        a = a->next;
      } else {
        tail->next = b;
        b = b->next;
      }
    }
    // Unlike solution on 2016-11-19, We use ternary conditional expression on 2016-12-21
    // Use nullptr on 2017-01-03
    tail->next = a != nullptr ? a : b;
    return dummy.next;
  }
};

// Method 2: with divide-and-conquer
// Refer to: http://bangbingsyb.blogspot.com/2014/11/leetcode-merge-k-sorted-lists.html
// Time: 26ms, beats 89.1% cpp solutions
// Time complexity: O(nlogk)
// Date: 2016-11-19
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    if (lists.size() == 1) return lists.front();
    vector<ListNode*> next;
    for (size_t i = 0; i +1 < lists.size(); i += 2)
      next.push_back(merge(lists[i], lists[i + 1]));
    if (lists.size() % 2) next.push_back(lists.back());
    return mergeKLists(next);
  }

 private:
  ListNode* merge(ListNode *a, ListNode *b) {
    shared_ptr<ListNode> dummy(new ListNode(0));
    auto tail = dummy.get();
    for (; a && b; tail = tail->next) {
      if (a->val < b->val) {
        tail->next = a;
        a = a->next;
      } else {
        tail->next = b;
        b = b->next;
      }
    }
    if (a) tail->next = a;
    if (b) tail->next = b;
    return dummy->next;
  }
};

// Method 1: with priority_queue
// Time: 40ms, beats 60% cpp solutions
// Time: 29ms, beats 64% cpp solutions (Record on 2017-07-27)
// Time complexity: O(nlogk)
// Date: 2016-11-19
// Last modified: 2017-01-03
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, comp> q;
    for (auto head : lists)
      if (head != nullptr) q.push(head);  // introduce nullptr on 2017-01-03
    ListNode *res = nullptr, *tail = nullptr;
    while (!q.empty()) {
      // introduce nullptr on 2017-01-03
      if (res == nullptr) {
        res = tail = q.top();
      } else {
        tail->next = q.top();
        tail = tail->next;
      }
      q.pop();
      // introduce nullptr on 2017-01-03
      if (tail->next != nullptr) q.push(tail->next);
    }
    return res;
  }

 private:
  struct comp {
    bool operator ()(ListNode* lhs, ListNode* rhs) {
      return lhs->val > rhs->val;
    }
  };
};

// Date: 2014-06
class Solution 
{
public:
  struct cmp
  {
    bool operator () (const ListNode* a, const ListNode* b)
    {
      return a->val > b->val;
    }
  };
  ListNode *mergeKLists(vector<ListNode *> &lists) 
  {
    ListNode *head=NULL, *cur=NULL;
    priority_queue<ListNode*, vector<ListNode*>, cmp> ss;

    for (auto it = lists.begin(); it != lists.end(); ++ it)
    {
      if (*it != NULL)
      {
        ss.push(*it);
      }
    }
    while(ss.empty() == false)
    {
      auto top = ss.top();
      if (head == NULL)
      {
        head = cur = top;
      } else
      {
        cur->next = top;
        cur = cur->next;
      }
      ss.pop();
      if (top->next != NULL)
      {
        ss.push(top->next);
      }
    }

    return head;
  }
};

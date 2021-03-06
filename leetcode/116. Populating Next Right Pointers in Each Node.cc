// Copyright 2017 Qi Wang
// Date: 2017-11-11
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    if (root == nullptr) return;
    TreeLinkNode* cur = root;
    while (cur->left != nullptr) {
      TreeLinkNode* next_level_head = nullptr;
      for (TreeLinkNode* prev = nullptr; cur != nullptr; cur = cur->next) {
        if (next_level_head == nullptr) {
          next_level_head = cur->left;
          prev = cur->left;
        } else {
          prev->next = cur->left;
          prev = cur->left;
        }
        prev->next = cur->right;
        prev = cur->right;
      }
      cur = next_level_head;
    }
  }
};
 
// Date: 2017-11-10
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    if (root == nullptr) return;
    // Nonleaf node
    if (root->left != nullptr) {
      root->left->next = root->right;
      if (root->next != nullptr) {
        root->right->next = root->next->left;
      }
      connect(root->left);
      connect(root->right);
    }
  }
};

// Date: 2017-08-01
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    if (root != nullptr) {
      Connect(root, nullptr);
    }
  }

 private:
  void Connect(TreeLinkNode *root, TreeLinkNode *right) {
    root->next = right;
    if (root->left != nullptr) {
      Connect(root->left, root->right);
      Connect(root->right, right != nullptr ? right->left : nullptr);
    }
  }
};

class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
      queue<TreeLinkNode*> nodes;
      queue<TreeLinkNode*> children;
      nodes.push(root);
      nodes.push(NULL);
      while ( nodes.front() != NULL )
      {
        auto cur = nodes.front();
        nodes.pop();
        cur->next = nodes.front();
        if (cur->left != NULL)
         {
           children.push( cur->left );
         }
         if (cur->right != NULL)
        {
             children.push( cur->right );
         }
         if (nodes.front() == NULL)
         {
          nodes = children;
          nodes.push(NULL);
          while (children.empty() == false)
          {
            children.pop();
          }
        }
      }
    }
};
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    preorder(root, ans);
    return ans;
  }

 private:
  void preorder(TreeNode* root, vector<int>& ans) {
    if (root == nullptr)
      return;
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  Solution sol;
  vector<int> result = sol.preorderTraversal(root);

  for (int val : result) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}

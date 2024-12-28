#include <iostream>
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
  int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr)
      return 0;

    int ans = 0;

    if (root->left) {
      if (root->left->left == nullptr && root->left->right == nullptr)
        ans += root->left->val;
      else
        ans += sumOfLeftLeaves(root->left);
    }
    ans += sumOfLeftLeaves(root->right);

    return ans;
  }
};

int main() {
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution solution;
  cout << "Sum of left leaves: " << solution.sumOfLeftLeaves(root) << endl;

  return 0;
}

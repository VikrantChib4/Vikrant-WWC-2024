#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> count(n + 1);
    for (vector<int>& t : trust) {
      --count[t[0]];
      ++count[t[1]];
    }
    for (int i = 1; i < n + 1; ++i)
      if (count[i] == n - 1)
        return i;
    return -1;
  }
};

int main() {
  Solution solution;
  int n = 3;
  vector<vector<int>> trust = {{1, 3}, {2, 3}};
  cout << solution.findJudge(n, trust) << endl;
  return 0;
}

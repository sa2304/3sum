#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    // FIXME
    return {};
  }
};

void TestThreeSum() {
  Solution s;
  {
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets{{-1, -1, 2}, {-1, 0, 1}};
    assert(triplets == s.threeSum(nums));
  }
  {
    vector<int> nums{};
    vector<vector<int>> triplets{};
    assert(triplets == s.threeSum(nums));
  }
  {
    vector<int> nums{0};
    vector<vector<int>> triplets{};
    assert(triplets == s.threeSum(nums));
  }
}

int main() {
  TestThreeSum();
  std::cout << "Ok!" << std::endl;
  return 0;
}

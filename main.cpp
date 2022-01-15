#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  template<class Iter>
  void advanceToNextNumber(Iter& iter, Iter end, bool left_to_right) {
    if (iter != end) {
      auto val = *iter;
      while (iter != end and val == *iter) {
        if (left_to_right) { ++iter; }
        else { --iter; }
      }
    }
  }

 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    if (not nums.empty()) {
      sort(nums.begin(), nums.end());
      auto left = nums.begin();
      auto right = prev(nums.end());
      while (left < right) {
        const int a = *left;
        auto duplets = twoSum(next(left), right, -a);
        for (const auto&[a, b]: duplets) {
          result.push_back({*left, a, b});
        }
        advanceToNextNumber(left, right, true);
      }
    }

    return result;
  }

  template<class Iter>
  vector<pair<int, int>> twoSum(Iter left, Iter right, int target) {
    vector<pair<int, int>> result;
    while (left < right) {
      const int l = *left;
      const int r = *right;
      const int sum = l + r;
      if (sum < target) { ++left; }
      else if (target < sum) { --right; }
      else {
        result.push_back({*left, *right});
        advanceToNextNumber(left, right, true);
        advanceToNextNumber(right, left, false);
      }
    }

    return result;
  }
};

void TestTwoSum() {
  Solution s;
  {
    vector<int> nums{-7, -5, -3, -1, 0, 2, 4, 6, 8};
    {
      vector<pair<int, int>> expected{{-7, -1}, {-5, -3}};
      assert(expected == s.twoSum(nums.begin(), prev(nums.end()), -8));
    }
  }
}

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
  {
    vector<int> nums{-2,0,0,2,2};
    vector<vector<int>> triplets{{-2,0,2}};
    assert(triplets == s.threeSum(nums));
  }
}

int main() {
  TestTwoSum();
  TestThreeSum();
  std::cout << "Ok!" << std::endl;
  return 0;
}

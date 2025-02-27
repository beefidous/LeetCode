class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int prefix = 0;
    unordered_map<int, int> prefixToIndex{{0, -1}};

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      if (k != 0)
        prefix %= k;
      if (prefixToIndex.count(prefix)) {
        if (i - prefixToIndex[prefix] > 1)
          return true;
      } else {
        // Only add if absent, because the previous index is better
        prefixToIndex[prefix] = i;
      }
    }

    return false;
  }
};

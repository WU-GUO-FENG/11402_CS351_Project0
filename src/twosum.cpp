#include "include/twosum.hpp"
#include <unordered_map>

/**
 * TwoSumArray: 暴力法 (O(n^2))
 */
std::vector<int> TwoSumArray(const std::vector<int>& nums, int target) {
    // 基礎驗證
    if (nums.size() < 2) return {};

    // 使用 size_t 避免與 signed int 比較時的警告
    for (std::size_t i = 0; i < nums.size(); ++i) {
        for (std::size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {static_cast<int>(i), static_cast<int>(j)};
            }
        }
    }
    return {};
}

/**
 * TwoSumHashTable: 哈希表法 (O(n))
 */
std::vector<int> TwoSumHashTable(const std::vector<int>& nums, int target) {
    if (nums.size() < 2) return {};

    std::unordered_map<int, int> num_map;
    num_map.reserve(nums.size()); 

    for (std::size_t i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        // C++20 特性：使用 .contains() 檢查 Key
        if (num_map.contains(complement)) {
            return {num_map[complement], static_cast<int>(i)};
        }

        // 若沒找到，存入當前數值與索引
        num_map[nums[i]] = static_cast<int>(i);
    }

    return {};
}
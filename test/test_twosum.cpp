#include <gtest/gtest.h>
#include <fstream>
#include <vector>
#include "include/twosum.hpp"

// 測試讀取檔案並驗證的邏輯
TEST(TwoSumFileTest, RunAllFromDataTxt) {
    std::ifstream infile("test/data.txt");
    std::string line;
    
    while (std::getline(infile, line)) {
        if (line.empty() || line[0] == '#') continue; // 跳過註釋

        std::stringstream ss(line);
        int n, target, exp1, exp2;
        ss >> n >> target;

        std::vector<int> nums(n);
        for (int i = 0; i < n; ++i) ss >> nums[i];
        ss >> exp1 >> exp2;

        std::vector<int> expected;
        if (exp1 != -1) expected = {exp1, exp2};

        // 同時測試兩種實作
        EXPECT_EQ(TwoSumArray(nums, target), expected);
        EXPECT_EQ(TwoSumHashTable(nums, target), expected);
    }
}

// TC-09: 性能測試 (大數據)
TEST(TwoSumPerformance, HashTableLargeData) {
    std::vector<int> nums(10000);
    for (int i = 0; i < 10000; ++i) nums[i] = i;
    int target = 19997; // 9998 + 9999
    
    auto start = std::chrono::steady_clock::now();
    auto res = TwoSumHashTable(nums, target);
    auto end = std::chrono::steady_clock::now();
    
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    EXPECT_EQ(res, (std::vector<int>{9998, 9999}));
    EXPECT_LT(diff, 10); // 驗證是否在 10ms 內完成
}
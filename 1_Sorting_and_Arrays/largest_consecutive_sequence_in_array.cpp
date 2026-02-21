#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unordered_set>

using namespace std;

 class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        
        int longest = 0;

        for(int num : st) {

            // Only start if it's the beginning of a sequence
            if(st.find(num - 1) == st.end()) {
                
                int currentNum = num;
                int count = 1;

                while(st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
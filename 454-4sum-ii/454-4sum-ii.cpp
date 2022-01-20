class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        
        unordered_map<int, int>  abSum;
        for(auto i : nums1) {
            for(auto j : nums2) {
                ++abSum[i+j];
            }
        }
        
        int count = 0;
        
        for(auto i : nums3) {
            for(auto j : nums4) {
                auto it = abSum.find(0-i-j);
                if(it != abSum.end()) {
                    count += it->second;
                }
            }
        }
        return count;
        
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1,s2;
        
        vector<int>ans;
        
        for(auto i:nums1)
            s1.insert(i);
        
        for(auto i:nums2)
            s2.insert(i);
        
        for(auto i:s1)
            if(s2.find(i)!=s2.end())
                ans.push_back(i);
            
        return ans;
    }
};
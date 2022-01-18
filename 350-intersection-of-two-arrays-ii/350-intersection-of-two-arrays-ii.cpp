class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m1;
        map<int, int> m2;
        
        vector<int>ans;
        
        for(auto i:nums1)
            m1[i]++;
        
        for(auto i:nums2)
            m2[i]++;
        
        for(auto i:m1)
            if(m2.find(i.first)!=m2.end())
            {
                int l = i.second < m2[i.first] ? i.second : m2[i.first];
                
                for(int j=0;j<l;j++)
                    ans.push_back(i.first);
            }
        
        
        return ans;
    }
};
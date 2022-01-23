class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        
        for(int i=0;i<nums1.size();i++){
            int x  = -1;
            for(int j=nums2.size()-1;j>=0;j--){
                if(nums1[i] == nums2[j])
                    break;
                else
                    if(nums1[i]<nums2[j])
                        x = nums2[j];
            }
            ans.push_back(x);
        }
        
        
        return ans;
    }
};
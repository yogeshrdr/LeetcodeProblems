class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> mp;
        vector<string> v;
	    int index=INT_MAX;
        
	     for(int i=0;i<list1.size();i++)
		     mp[list1[i]]=i;
        
        for(int i=0;i<list2.size();i++){
            
            if(mp.find(list2[i])!=mp.end()){
                
                if(mp[list2[i]]+i <index)
                {
				    v.clear();
				    index=mp[list2[i]]+i;
				    v.push_back(list2[i]);
			    }
                
                else if(mp[list2[i]]+i==index)
                   v.push_back(list2[i]);
                
            }
        }
        
        return v;
         
	
    }
};
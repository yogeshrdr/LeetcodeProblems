class Solution {
public:
    string capitalizeTitle(string title) {
       int i=0;
    
	    while(i<title.size()){
            int j=i;   
            while(i<title.size() and title[i]!=32) {
                title[i]=tolower(title[i]);
                i++;
            }

		    if(i-j>2) 
                title[j]=toupper(title[j]);
            i++;
        }
        
        return title;
    }
};
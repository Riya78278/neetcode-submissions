class Solution {
public:
    string minWindow(string s, string t) {
        int left=0;
        int count=0;
        int minilen=INT_MAX;
        int index=-1;
        int right=0;
        int n=s.size();
        int m=t.size();
        if(n<m){
            return "";
        }
        vector<int>hash(256,0);
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }

        while(right<n){
            if(hash[s[right]]>0){
                count++;
            }
            hash[s[right]]--;

            while(count==m){
                if(right-left+1<minilen){
                    minilen=right-left+1;
                    index=left;
                }
                hash[s[left]]++;
                if(hash[s[left]]>0){
                    count--;
                }
                left++;
            }
            right++;
        }
        return index==-1? "":s.substr(index,minilen);


    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(int i=0;i<n;i++){
            freq1[s1[i]-'a']++;
        }

        int left=0;
        int right=0;

        while(right <s2.size()){
            freq2[s2[right]-'a']++;

            if(right-left+1>n){
                freq2[s2[left]-'a']--;
                left++;
            }
            if(freq1==freq2){
                return true;
            }
            right++;
        }
        return false;

    }
};

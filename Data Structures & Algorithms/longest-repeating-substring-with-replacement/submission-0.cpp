class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int>freq(26,0);

        int left=0;
        int maxfreq=0;
        int maxlen=0;
        for(int right=0;right<n;right++){

            freq[s[right]-'A']++;
            maxfreq=max(maxfreq,freq[s[right]-'A']);
            int changes= (right-left+1) - maxfreq;

            while(changes >k){
                freq[s[left]-'A']--;
                left++;

                changes= (right-left+1) - maxfreq;
            }
            maxlen=max(maxlen,right-left+1);

        }
        return maxlen;
    }
};

class Solution {
private:
    bool canbe_eat(vector<int>& piles,int h,int mid){
        int n=piles.size();
        int actualhours=0;

        for(auto &x:piles){
            actualhours +=x/mid;

            if(x%mid != 0){
                actualhours++;
            }
        }
        return actualhours<=h;
    }    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();

        int left=1;
        int right= *max_element(piles.begin(),piles.end());
        while(left <right){
            int mid=left+(right-left)/2;
            if(canbe_eat(piles,h,mid)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};

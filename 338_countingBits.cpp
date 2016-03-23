class Solution {
public:
    vector<int> countBits(int num) {
        if(num <= 0)
            return vector<int>(1,0);
            
        vector<int> cnt(num+1);
        cnt[0] = 0;
        for(int i=0; i<=num; i++)
        {
            if(i&0x01)   //为基数
                cnt[i] = cnt[i>>1]+1;
            else
                cnt[i] = cnt[i>>1];
        }
        
        return cnt;
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s = 0, e = nums.size() - 1, m = 0, c = 0, sl = 0, sr = 0;
        while(s <= e) {
            sl = 0, sr = 0;
            m = s + (e-s)/2;
            c = m - 1;
            while(c >= 0) {
                sl = sl +nums[c];
                c--;
            }
            c = m + 1;
            while(c != nums.size()) {
                sr = sr +nums[c];
                c++;
            }
            
            if(sl == sr)
                return m;
            else if(abs(sl) < abs(sr)) {
                s = m + 1;
            }
                
            else {
                e = m - 1;
            }
        }
        return -1;
    }
};
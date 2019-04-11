class Solution {
public:
    //https://www.cnblogs.com/allzy/p/5162815.html
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
            return 0;
        return MaxSum(array, 0, array.size()-1);
    }
    
    int MaxSum(vector<int> dat, int l, int r){
        if(l == r){
            return dat[l];
        }
        int maxmidLeft, maxmidRight, sumLeft, sumRight, maxMid;
        int midpos = (l + r) / 2;
        int lindex = midpos-1, rindex = midpos+1;
        sumLeft = sumRight = maxmidLeft = maxmidRight = dat[midpos];
        while(lindex >= l){
            sumLeft += dat[lindex--];
            if(sumLeft > maxmidLeft)
                maxmidLeft = sumLeft;
        }
        while(rindex <= r){
            sumRight += dat[rindex++];
            if(sumRight > maxmidRight)
                maxmidRight = sumRight;
        }
        maxMid = maxmidLeft + maxmidRight - dat[midpos];
        
        int cleft = MaxSum(dat, l, midpos);
        int cright = MaxSum(dat, midpos+1, r);
        
        return max(maxMid, max(cleft, cright));
    }
};

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
    // there have four ways to Find in the array
    //1.from top right to down left 1.1 check row firstly and check column later 1.2 inverse
    //2.from down left to top right 2.1 check row firstly and check column later 2.2 inverse
    
    // this is from tr to dl and check row firstly, also can check column firstyly
      int r = 0;
      int c = array.front().size()-1;
      while(r < array.size() && c >= 0){ 
        if(target == array[r][c])        
          return true;
        else if(target > array[r][c])    //{array[r][i]} < target, so ++r;
          ++r;
        else --c;                        // array[r][c] > target, maybe target is in this row, so c--
      }
      return false;                      
    }
};



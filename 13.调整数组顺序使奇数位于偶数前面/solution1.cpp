class Solution {
public:
    void reOrderArray(vector<int> &array) {
        // relative position should not be changed.
        //--------way one
        /*
        vector<int> odd;
        for(int i = 0; i < array.size(); ++i){
            if(array[i] % 2)
                odd.push_back(array[i]);
        }
        int k = array.size()-1;
        for(int i = array.size()-1; i >= 0; --i){
            if(array[i] % 2 == 0){
                array[k--] = array[i];
            }
        }
        for(int i = 0; i < odd.size(); ++i)
            array[i] = odd[i];
        */
        //--------way two
        int k = 0; 
        for(int i = 0; i < array.size(); ++i){
            if(array[i]%2==1){
                int j = i;
                int ti = array[j];
                while(j > k){
                   int temp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = array[j];
                    j--;
                } 
                array[j] = ti;
                k++;
            }
        }
        
    }
};

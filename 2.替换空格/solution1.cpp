class Solution {
public:
	void replaceSpace(char *str,int length) {
        //there are two assumption
        //1.str is not null
        //2.the length of str pointer directing is enougth to embreace the result
        
        //two way to replace
        //1:O(n^2)when encounter a ' ' from end to begin, adjust the length and move the elements
        //2:O(N)count the number of the ' ' in str, and move in the result placement.
        // way 1 exsit repeat move
        
        int sNum = 0;
        for(int i = 0; i < length; ++i){
            if(str[i] == ' ') 
                ++sNum;
        }
        int src_index = length - 1;
        int res_index = length + 2*sNum - 1;
    
        while(src_index >= 0){
            if(str[src_index] == ' '){
                str[res_index--] = '0';
                str[res_index--] = '2';
                str[res_index--] = '%';
                src_index--;
            }
            else str[res_index--] = str[src_index--];
        }
	}
};

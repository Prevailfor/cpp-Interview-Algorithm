class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
       if(sequence.empty())
           return false;
        return Judge(sequence);
    }
    bool Judge(vector<int> sequence){
         if(sequence.size() <= 1)
            return true;

        int midposlater = sequence.size()-1;
        for(int i = 0; i < sequence.size()-1; ++i)
            if(sequence[i] > sequence.back()){ // find the right-kid tree index
                midposlater = i;
                break;
            }

        for(int i = midposlater; i < sequence.size()-1; ++i){ // check whether the tree is satify the root node value is lager the right-kid tree node.
            if(sequence[i] < sequence.back())
                return false;
        }
        
        return Judge(vector<int>(sequence.begin(), sequence.begin()+midposlater)) &&    
                    Judge(vector<int>(sequence.begin()+midposlater, sequence.end()-1));
        
        // Non-recursion way
        /*
        int size = sequence.size();
        if(0==size)return false;
 
        int i = 0;
        while(--size)
        {
            while(sequence[i++]<sequence[size]);
            while(sequence[i++]>sequence[size]);
 
            if(i<size)return false;
            i=0;
        }
        return true;
        */
    }
};
 

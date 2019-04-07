class Solution {
public:
    // use recursion: 3 step;
    //1. find the boundry of the BST's left tree and right tree, and check whether the right tree's value is larger than the root node value
    //2. if step 1 is ture, check whether the left tree satisfy the characteristic of BST.
    //3. if step 1 is true, check whether the right tree satisfy the characteristic of BST.
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
    }
};
 

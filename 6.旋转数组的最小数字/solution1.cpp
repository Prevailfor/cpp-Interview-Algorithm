class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int fir = 0;                // direct the first sorted part of the rotateArray
        int ed = rotateArray.size()-1; // direct the end sorted part of the rotateArray.
        int mid = fir;                 // if rotateArray is sorted, that is to say that rotate 0 elements, so 
                                       // rotateArrayp[0] is the result
        while(rotateArray[fir] >= rotateArray[ed]){ // change the condition to be true allright.
            if(fir + 1 == ed){
                mid = ed;
                break;
            }
            mid = fir + (ed - fir) / 2;            // use binary search to find
            if(rotateArray[fir] == rotateArray[mid] &&  // if the three node is same, the position of result is hard to verify. so to visit
               rotateArray[mid] == rotateArray[ed]){    // all the element between the search scope.
                for(int i = fir+1; i <= ed; ++i){
                    if(rotateArray[i] < rotateArray[mid])
                        mid = i;
                }
                break;
            }
            
            if(rotateArray[fir] <= rotateArray[mid]) // result be the end part
                fir = mid;
            else if(rotateArray[mid] <= rotateArray[ed]) // result be in the first part
                ed = mid;
        }
        return rotateArray[mid];
    }
};

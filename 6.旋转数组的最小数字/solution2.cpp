class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int fir = 0;                // direct the first sorted part of the rotateArray
        int ed = rotateArray.size()-1; // direct the end sorted part of the rotateArray.
        int mid = fir;                 // if rotateArray is sorted, that is to say that rotate 0 elements, so 
        /*                               // rotateArrayp[0] is the result
        while(rotateArray[fir] >= rotateArray[ed]){ 
            if(fir + 1 == ed){
                mid = ed;
                break;
            }
            mid = fir + (ed - fir) / 2;            // use binary search to find
            if(rotateArray[fir] == rotateArray[mid] && 
               rotateArray[mid] == rotateArray[ed]){
                for(int i = fir+1; i <= ed; ++i){
                    if(rotateArray[i] < rotateArray[mid])
                        mid = i;
                }
                break;
            }
            
            if(rotateArray[fir] <= rotateArray[mid])
                fir = mid;
            else if(rotateArray[mid] <= rotateArray[ed])
                ed = mid;
        }
        */
        while(fir < ed){
            mid = (fir + ed) / 2;
            if(rotateArray[mid] > rotateArray[ed])
                fir = mid + 1;
            else if(rotateArray[mid] < rotateArray[ed])
                ed = mid;
            else if(rotateArray[mid] == rotateArray[ed])
                ed = ed - 1;
        }
        return rotateArray[fir];
    }
};

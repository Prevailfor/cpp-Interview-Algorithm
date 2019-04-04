class Solution {
public:
     int  NumberOf1(int n) {
         /*
         //---------------------------solution1 use 1, 10, 100,... do & with n to check
         //every one.
         int flag = 1;
         int counts = 0;
         int i = 0;
         while(flag!=0){
             if(flag & n) counts++;
             flag = flag << 1;          // flag = flag / 2 <==> flag = flag >> 1;
         }
         return counts;
         */
         
         int cts = 0;
         while(n != 0){
             cts++;
             n = (n-1) & n;
         }
         return cts;
     }
};

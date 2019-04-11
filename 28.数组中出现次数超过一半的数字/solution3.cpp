class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        int markNum;
        int times = 0;
        for(int i = 0; i < numbers.size(); ++i){
            if(times == 0){
                times++;
                markNum = numbers[i];
            }
            else if(markNum == numbers[i])
                times++;
            else if(markNum != numbers[i])
                times--;
        }
        if(times == 0) return 0;
        int cts = 0;
        for(int i = 0; i < numbers.size(); ++i)
            if(markNum == numbers[i]) cts++;
        if(cts > (numbers.size()>>1))
            return markNum;
        else return 0;
    }
};

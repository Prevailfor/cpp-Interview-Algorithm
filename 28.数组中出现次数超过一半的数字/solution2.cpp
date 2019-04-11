class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        int middle = numbers.size()>>1;
        int s = 0, e = numbers.size()-1;
        int index = Partition(numbers, s, e);
        while(index != middle){
            if(index < middle)
                s = index + 1;
            else if(index > middle)
                e = index - 1;
            index = Partition(numbers, s, e);
        }
        int cts = 0;
        for(int i = 0; i < numbers.size(); ++i)
            if(numbers[i] == numbers[index])
                cts++;
        if(cts > middle)
            return numbers[index];
        else return 0;
    }
    
    int Partition(vector<int> dat, int s, int e){
        int i = s;
        int j = e;
        int temp = dat[s];
        while(i < j){
            while(i<j && dat[j]>=temp) j--;
            dat[i] = dat[j];
            while(i<j && dat[i]<=temp) i++;
            dat[j] = dat[i];
        }
        dat[i] = temp;
        return i;
    }
};

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < numbers.size(); ++i)
            if(mp.find(numbers[i]) != mp.end())
                mp[numbers[i]]++;
            else
                mp[numbers[i]] = 1;
        int max = -1;
        int rt;
        for(unordered_map<int, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter)
            if(iter->second > max){
                max = iter->second;
                rt = iter->first;
            }
        if(max > numbers.size()/2)
            return rt;
        else
            return 0;
    }
};

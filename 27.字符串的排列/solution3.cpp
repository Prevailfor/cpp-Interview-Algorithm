class Solution {
public:
    //way two; implement the nextpermutation of stl
    //the definition of nexepermutation of one list is that there is no other list between the two list
    //the nextpermution is basing becoming bigger order
    //three step to operate:
    //1. from the end to the start to find the first place of list[sindex-1]<list[sindex].
    //2. from sindex to the last to find the last place of list[lindex] > list[lindex-1].
    //3. reverse the elements of from list[sindex-1] to list[lindex-1].
    vector<string> Permutation(string str) {
        vector<string > res;
        if(str.empty()){
            return res;   
        }            
        sort(str.begin(), str.end());
        res.push_back(str);
        //calculate the next permulation
        while(1){
            int sindex = str.size()-1; // to find str[sindex-1] < str[sindex];
            while(sindex>=1 && str[sindex-1]>=str[sindex])
                sindex--;
            if(sindex == 0) break;
            int lindex = sindex;
            while(lindex<str.size() && str[lindex]>str[sindex-1])
                lindex++;
            str[sindex-1] = str[lindex-1]+str[sindex-1]-(str[lindex-1]=str[sindex-1]);
            reversestr(str, sindex);
            res.push_back(str);
        }
        return res;
    }
    void reversestr(string &str, int k){
        int a = k;
        int b = str.size()-1;
        while(a < b){
            str[a] = str[a] + str[b] - (str[b] = str[a]);
            a++;
            b--;
        }
    }
};

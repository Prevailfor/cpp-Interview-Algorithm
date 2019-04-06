class Solution {
public:
    // imitate the progress of push and pop
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        /*------------ writting one: intuitive way
        stack<int > aux;
        int popv = 0;
        int pushv = 0;
        while(popv != popV.size()){
            while(aux.empty() || aux.top()!=popV[popv]){
                if(pushv == pushV.size())
                    break;
                aux.push(pushV[pushv++]);
            }
            if(aux.top()!=popV[popv])
                break;
            aux.pop();
            popv++;
        }
        
        return aux.empty();
        */
        
        //----------writting two: brief way
        stack<int> st;
        for(int i = 0, j = 0; i < pushV.size(); ++i){
            st.push(pushV[i]);
            while(j<popV.size() && !st.empty() && st.top()==popV[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

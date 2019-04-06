bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int i;
        for(i = 0; i < pushV.size(); ++i){
            if(pushV[i] == popV[0])
                break;
        }
        int fd;
        if(i == pushV.size())
            return false;
        while(pushV.size() >= 1){
            pushV.erase(pushV.begin()+i);
            popV.erase(popV.begin());
            fd = 0;
            if(i<pushV.size()){
                int j;
                for(j = i; j < pushV.size();++j)
                    if(pushV[j] == popV[0])
                        break;
                if(j != pushV.size()){
                    fd = 1;
                    i = j;
                }
                    
            }
            else if(i >= 1 && i-1 < pushV.size() && pushV[i-1] == popV[0]){
                i = i-1;
                fd = 1;
            }
            if(!fd)
                break;
        }
        if(pushV.empty())
            return true;
        else
            return false;
    }

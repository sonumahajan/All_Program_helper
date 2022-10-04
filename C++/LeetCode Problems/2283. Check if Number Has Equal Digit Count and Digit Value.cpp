    bool digitCount(string num) {
        unordered_map<int,int> mp;
        for(int i=0;i<num.size();i++)
            mp[i]=num[i]-'0';
        for(int i=0;i<num.size();i++){
            mp[num[i]-'0']--;
            if(mp[num[i]-'0']<0)    return false;
        }
        for(int i=0;i<num.size();i++){
            if(mp[num[i]-'0']>0)    return false;
        }
        return true;
    }

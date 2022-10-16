    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int count=0;
        vector<int> v;
        for(int i=0;i<rocks.size();i++){
            int space=capacity[i]-rocks[i];
            v.push_back(space);
        }
        sort(v.begin(),v.end());
        for(int i:v){
            if(i<=additionalRocks)    {
                additionalRocks-=i;
                count++;
            }
        }
        return count;
    }

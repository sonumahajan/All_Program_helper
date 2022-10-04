class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int prev=neededTime[0];
        bool fl=false;
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                fl=true;
                prev=max(prev,neededTime[i]);
                neededTime[i]+=neededTime[i-1];
            }
            else if(fl)ans+=neededTime[i-1]-prev,fl=false,prev=neededTime[i];
            else prev=neededTime[i];
        }
        if(fl)ans+=neededTime[colors.size()-1]-prev;
        return ans;
    }
};
class Solution {
public:
    struct comp {
        int getOnes(int n)
        {
        int count=0;
        while(n>0)
        {
            n=n&(n-1);
            count++;
        }
        return count;
        }
        
        bool operator() (int a, int b) {
            int aones = getOnes(a);
            int bones = getOnes(b);
            if(aones == bones) {
                return a<=b;
            }
            return aones<bones;
        }
    };
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp());
        return arr;
    }
};

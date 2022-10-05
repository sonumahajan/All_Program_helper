    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int water=0;
        while(i<j){
            int h = min(height[i],height[j]);
            water=max(water,(h*(j-i)));
            if(height[i]<=h) i++;
            if(height[j]<=h) j--;
            
        }
        return water;
    }

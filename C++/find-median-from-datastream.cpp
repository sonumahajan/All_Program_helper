// brute force :  each time we will sort .
                 // TC : O(NlogN)*N = O(N*NLogN)

// optimal approach : using heaps 
                    // TC : O(NlogN) 




// data stream : running stream of data means we will get data one by one .
class MedianFinder {
public:
    
    priority_queue<int>maxheap ; // Max-Heap
    priority_queue<int,vector<int>,greater<int>>minheap ;// Min-Heap
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(maxheap.empty() and minheap.empty())
        {
            maxheap.push(num) ;
        }
        
        else 
        {
            if(maxheap.top() < num)
            {
                minheap.push(num) ;
            }
            else
                maxheap.push(num) ;
        }
        
        // Lets balance these heaps each time
        int n = maxheap.size() ;
        int m = minheap.size() ;
        
       if(n-m==2 || n-m==-2)
       {
            if(m > n) 
            {
               int element = minheap.top() ;
               minheap.pop() ;
               maxheap.push(element) ;
            }
           else
            {
               int element = maxheap.top() ; 
               maxheap.pop() ;
               minheap.push(element) ;
            }
       }
    }
    
    double findMedian() {
        
        int n = maxheap.size() ;
        int m = minheap.size() ;
        
        if((n+m)%2==0)
        {
            return (maxheap.top()+minheap.top())/2.0 ;
        }
        else
        {
            if(n>m) 
                return maxheap.top() ;
            else
                return minheap.top() ;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

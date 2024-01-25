#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
	priority_queue<int> maxheap;
	priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
		while(!maxheap.empty())maxheap.pop();
		while(!minheap.empty())minheap.pop();
    }
    
    void addNum(int num) {
		if(maxheap.size()==minheap.size()){
			maxheap.push(num);
		}
		else{
			minheap.push(num);
		}
        while(!minheap.empty()&&maxheap.top()>minheap.top()){
			int t = maxheap.top();
			maxheap.pop();
			maxheap.push(minheap.top());
			minheap.pop();
			minheap.push(t);
		}
    }
    
    double findMedian() {
		if((maxheap.size()+minheap.size())%2)
			return maxheap.top();
        return (maxheap.top()+minheap.top())/2.0;
    }
};

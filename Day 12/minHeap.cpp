void pushHeap(vector<int>&h,int q){
	h.push_back(q);// add the element in end of heap
	int n =h.size()-1;
	while(n){ 
		if(h[n]   <   h[(n-1)/2]){
			swap(h[n],h[(n-1)/2]);
			// check if parent heap((n-1)/2) is greater then current(initialy last new one which made in the funtion first) then swap with perent.             
		}
		n= (n-1)/2;
	}
}
void remove(vector<int> &h){ // only for remove top most heap
	int n=0; // top will be remove;
	h[0]=INT_MAX;
	while(2*n+2  < h.size()){
	  if(h[2*n+1]<=h[2*n+2]){ // if left is smaller then righ then swap that index with left(2*n+1). 
		  swap(h[n] , h[2*n+1]);
		  n=2*n+1;
	  }
	  else{// else swap with right(2*n+2).  
		  swap(h[n],h[2*n+2]);
		  n=2*n+2;
	  }
	}  
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
   vector<int>h,ans;
    for(int i=0;i<q.size();i++){
        if(q[i][0]){// when q[i][0]=1 smallest elemeent of heap which will be  in top i.e h[0] will be print and then rermove;
            ans.push_back(h[0]);
            remove(h);
        }
        else{
            pushHeap(h,q[i][1]);// for pushing element in heap if q[i][0]=0; i.e for  0,2  0,1 .
        }
    }
    return ans;
}

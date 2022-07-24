	//Function to find the minimum number of platforms required at the
    //railway station such that no train waits.

	int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int maxplat = 1, currplat = 1;
    	int i=1, j=0;
    	
    	while(i<n && j<n){
    	    //if next train is arriving before departure of prev train
    	    if(arr[i] <= dep[j]){
    	        currplat++;
    	        i++;
    	    }
    	    else{
    	        currplat--;
    	        j++;
    	    }
    	    if(currplat > maxplat) maxplat = currplat;
    	}
    	return maxplat;
    }

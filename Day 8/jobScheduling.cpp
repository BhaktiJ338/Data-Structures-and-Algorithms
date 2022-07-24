struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job j1, Job j2){
        return j1.profit > j2.profit;
    }
    
    vector<int> JobScheduling(Job job[], int n) 
    { 
		//sort in descending order of profit
        sort(job, job+n, comp);
        
		//find maximum deadline
        int maxdead = job[0].dead;
        for(int i=1; i<n; i++){
            if(job[i].dead > maxdead) maxdead = job[i].dead;
        }
        int days[maxdead+1];
        for(int i=0; i<=maxdead; i++){
            days[i] = -1;
        }
        int pro = 0, jobcnt=0;
        for(int i=0; i<n; i++){
            for(int j=job[i].dead; j>0; j--){
                if(days[j] == -1){
                    days[j] = i;
                    jobcnt++;
                    pro += job[i].profit;
                    break;
                }
            }
        }
        vector<int>ans = {jobcnt, pro};
        
        return ans;
    } 
};

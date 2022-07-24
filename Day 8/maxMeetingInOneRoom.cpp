	struct meeting{
        int start, end, num;
    };
    
    static bool comparator(struct meeting m1, meeting m2){
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        else if(m1.num < m2.num) return true;
        else return false;
    }

    int maxMeetings(int start[], int end[], int n){
        struct meeting meet[n];
		
        for(int i=0; i<n; i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].num = i+1;
        }
		
        sort(meet, meet+n, comparator);
        int ans=1;
        int endtime = meet[0].end;
		
        for(int i=1; i<n; i++){
            if(meet[i].start > endtime){
                ans++;
                endtime = meet[i].end;
            }
        }
        return ans;
    }

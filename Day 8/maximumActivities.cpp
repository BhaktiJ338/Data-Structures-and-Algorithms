#include <bits/stdc++.h>

struct activity{
    int start;
    int end;
};

bool comparator(struct activity a1, activity a2){
    if(a1.end < a2.end) return true;
    else if(a1.end > a2.end) return false;
    else if(a1.start < a2.start) return true;
    return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    struct activity act[n];
    for(int i=0; i<n; i++){
        act[i].start = start[i];
        act[i].end = finish[i];
    }
    sort(act, act+n, comparator);
    
    int actcnt = 1, endtime=act[0].end;
    for(int i=1; i<n; i++){
        if(act[i].start >= endtime) {
            actcnt++;
            endtime = act[i].end;
        }
    }
    return actcnt;
}

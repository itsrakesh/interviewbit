/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 *
 * typedef struct Interval interval;
 */
/*
 * intervals : the array of interval
 * sz : number of entries in intervals
 * newInterval : new Interval to be inserted
 * len : populate the length of returned array of intervals in len
 */
interval* insert(interval *intervals, int sz, interval newInterval, int *len) {
    int i,j=0,off=0;
	interval *temp;
	temp=(interval *)malloc((sz+1)*sizeof(interval));
	for(i=0;i<sz;i++){
		if(intervals[i].start>=newInterval.end && !off){
			temp[j++]=newInterval;
			off=1;
			i=i-1;
		}else if(newInterval.start<intervals[i].start && newInterval.end<=intervals[i].end && !off){
		    temp[j].start=newInterval.start;
		    temp[j++].end=intervals[i].end;
		    off=1;
		}
		else if(newInterval.start<intervals[i].start &&newInterval.end>=intervals[i].end && !off){
		    temp[j].start=newInterval.start;
		    while(i<sz && newInterval.end>=intervals[i].end){
				if((i+1)<sz){
				    if(newInterval.end>=intervals[i+1].start){
				        i++;
				    }else{
				        break;
				    }
				}else
				    i++;
			}
			temp[j++].end=(i<sz)?((newInterval.end>=intervals[i].end)?newInterval.end:intervals[i].end):newInterval.end;
			off=1;
		}
		else if(newInterval.start>=intervals[i].start &&  newInterval.start<=intervals[i].end && newInterval.end>intervals[i].end ){
			temp[j].start=intervals[i].start;			
			while(i<sz && newInterval.end>=intervals[i].end){
				if((i+1)<sz){
				    if(newInterval.end>=intervals[i+1].start){
				        i++;
				    }else{
				        break;
				    }
				}else
				    i++;
			}
			temp[j++].end=(i<sz)?((newInterval.end>=intervals[i].end)?newInterval.end:intervals[i].end):newInterval.end;off=1;
		}else {
			temp[j++]=intervals[i];
		}	
	}
	if(off==0){
	    temp[j++]=newInterval; 
	}
	*len=j;
return temp;
}


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
 * len : populate the length of returned array of intervals in len
 */
void quicksort(interval *in,int first,int last){
    int pivot,j,i;
    interval temp;
    //temp=(interval *)malloc(sizeof(interval));
     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(in[i].start<=in[pivot].start&&i<last)
                 i++;
             while(in[j].start>in[pivot].start)
                 j--;
             if(i<j){
                 temp=in[i];
                  in[i]=in[j];
                  in[j]=temp;
             }
         }

         temp=in[pivot];
         in[pivot]=in[j];
         in[j]=temp;
         quicksort(in,first,j-1);
         quicksort(in,j+1,last);

    }
}
interval* merge(interval *intervals, int sz, int *len) {
    int i,j=0,tmp,offset=0;
	interval *temp;
	temp=(interval *)malloc((sz+1)*sizeof(interval));
	quicksort(intervals,0,sz-1);
// 	for(i=0;i<sz;i++){
// 	    printf("[%d %d],",intervals[i].start,intervals[i].end);
// 	}
// 	printf("\n");
	for(i=0;i<sz;i++){
		temp[j].start=intervals[i].start;
	tmp=intervals[i].end;
		while(i<sz && tmp>=intervals[i].end){
		    offset=0;
				i++;
				if(tmp<=intervals[i].end && tmp>=intervals[i].start && i<sz){
				    tmp=intervals[i].end;
				    offset=1;
				}
			}
			//printf("tmp.end: %d,i:%d,intervals[i].end:%d\n",tmp,i,intervals[i].end);
	temp[j++].end=(tmp>=intervals[i].end)?tmp:((i<sz && tmp>=intervals[i].start)?intervals[i].end:tmp);
	
	if(offset==0)i=i-1;	
	}	
	*len=j;

	return temp;
}


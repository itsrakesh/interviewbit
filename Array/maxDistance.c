/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int maximumGap(const int* A, int n1) {
    int i,j=0,max_diff=-1,local_max=0,k;
    int *sortedIndexArray=malloc(sizeof(int)*n1),*sortedIndexArrayIndex=malloc(sizeof(int)*n1);
    
    sortedIndexArray[j]=A[0];
    sortedIndexArrayIndex[j]=0;
    for(i=1;i<n1;i++){
        if(A[i]<sortedIndexArray[j]){
            sortedIndexArray[++j]=A[i];
            sortedIndexArrayIndex[j]=i;
        }
    }    
        for(i=n1-1;i>=0;i--){
            while(j>=0 && A[i]>=sortedIndexArray[j]){
                if((i-sortedIndexArrayIndex[j])>=max_diff)
                    max_diff=i-sortedIndexArrayIndex[j];
                    j=j-1;
            }
        }
    return (max_diff==-1)?sortedIndexArray[0]:max_diff;
}


/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int maxSubArray(const int* a, int n1) {
    int max_so_far = -99999, max_ending_here = -999999,i;
    int isNON=0;
    
    for (i = 0; i < n1; i++)
    {
        if(a[i]>=0 && isNON==0){
            isNON=1;
        }
    }
    for (i = 0; i < n1; i++)
    {
        
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            if(isNON==0){
                max_ending_here = max(max_ending_here,a[i]);
            }    
            else{
                max_ending_here=0;
            }    
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

int max(int a,int b){
    return (a>b)?a:b;
}


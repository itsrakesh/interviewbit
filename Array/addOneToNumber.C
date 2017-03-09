/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
int* plusOne(int* A, int n1, int *length_of_array) {
	// SAMPLE CODE
        /*
         * *length_of_array = n1 + 1; // length of result array
         * 
         * // DO STUFF HERE. NOTE : length_of_array can be n1 OR n1 + 1. 
         * return result;
         */
         int *result = (int *) malloc(n1* sizeof(int));
         *length_of_array=n1;
         int i,carry=1,temp;
         for(i=n1-1;i>=0;i--){
             result[i]=(A[i]+carry)%10;
             if(carry==1 && A[i]+carry<10){
                 carry=0;
             }
         }
         if(carry==1){
             *result = (int *) malloc(n1+1* sizeof(int));
             *length_of_array=n1+1;
             result[0]=1;
         }
         while(result[0]==0){
             i=0;
             temp=result[1];
             while(i<n1){
                 result[i++]=result[i];
             }
             *result = (int *) malloc(n1-1* sizeof(int));
             *length_of_array=n1-1;
             n1=n1-1;
             result[0]=temp;
         }
         return result;
}


/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in length_of_array
 */
int* maxset(int* A, int n1, int *length_of_array) {
    /*
     * Sample Code : 
     *  *length_of_array = 1;
     *  int * ret = (int *) malloc(sizeof(int) * *length_of_array);
     *  ret[0] = 1;
     *  return ret;
     */
     int cur_max_start_index=0,cur_max_end_index=0;
     int global_max_start_index=0,global_max_end_index=0,index_range=0;
     int i,j=0, *result,temp=0;
     long int global_max_sum=0,cur_max_sum=0,prev_max_sum=-1;
     for(i=0;i<n1;i++){
         cur_max_sum+=A[i];
         
         if(cur_max_sum>=prev_max_sum &&cur_max_sum>=0){
             cur_max_end_index=i;
             prev_max_sum=cur_max_sum;
         }
         if(prev_max_sum>=0 &&(global_max_sum<prev_max_sum ||index_range<(cur_max_end_index-cur_max_start_index)+1 &&global_max_sum==prev_max_sum) ){
                global_max_start_index=cur_max_start_index;
                global_max_end_index=cur_max_end_index;
                global_max_sum=prev_max_sum;
                temp=1;
                index_range=(global_max_end_index-global_max_start_index)+1;
         }
          if(cur_max_sum<prev_max_sum) {
              cur_max_sum=0;
             cur_max_start_index=i+1;
             prev_max_sum=0;
          } 
     }
        *length_of_array = (global_max_end_index-global_max_start_index)+temp; 
         result = (int *) malloc(sizeof(int) * *length_of_array);
        for(i=global_max_start_index;i<global_max_end_index+temp;i++){
            if(temp==1)
                result[j++]=A[i];
            }
        return result;
}

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
 struct elementtable{
     int e;
     int c;
 };
int repeatedNumber(const int* A, int n1) {
    int i=0,j=0,k,minCount=INT_MAX,minCountIndex=0,isFound=0;
    struct elementtable temp[3];
    
    for(i=0;i<3;i++) {
       temp[i].e = -1;
       temp[i].c = 0;
    }
    
    for(i=0;i<n1;i++){
        minCount=INT_MAX;
        isFound=0;
        for(j=0;j<3;j++){
            if(A[i]==temp[j].e){
                temp[j].c++;
                isFound=1;
            }
            if(temp[j].c<minCount){
                minCountIndex=j;
                minCount=temp[j].c;
            }
        }
        if(isFound==0){
            temp[minCountIndex].e=A[i];
            temp[minCountIndex].c=1;
        }
    }
    
   for (i=0; i<3; i++)
    {   
        // Calculate actual count of elements 
        int ac = 0;  // actual count
        for ( j=0; j<n1; j++){
            if (A[j] == temp[i].e)
                ac++;
        }
        // If actual count is more than n/k, then print it
        if (ac > n1/3){ 
            return temp[i].e;
        }    
    }
    return -1;
}


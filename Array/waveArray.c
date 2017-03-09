/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
 
 void waveArray(int *A,int n1){
    int i;
    for(i=0;i+1<n1;i=i+2){
        A[i]=A[i+1]+A[i]-(A[i+1]=A[i]);
    }
}
void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
   	// divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
	
}



int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;
		
   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}
int* wave(int* A, int n1, int *len1) {
    int i;
    
    quickSort(A,0,n1-1);
 
    *len1=n1;
    waveArray(A,n1);
    return A;
}


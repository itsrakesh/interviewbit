/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Void. Just modifies the args passed by reference 
 */

void rotate(int** A, int n11, int n12) {
    int i,j,n=(n11>n12)?n11:n12,temp;
    
    
    for(i=0;i<n/2;i++){
        for(j=i;j<n-i-1;j++){
            temp=A[i][j];
            A[i][j]=A[n-1-j][i];
            A[n-1-j][i]=A[n-1-i][n-1-j];
            A[n-1-i][n-1-j]=A[j][n-1-i];
            A[j][n-1-i]=temp;
        }
    }
}


/**
 * @input X : Integer array corresponding to the X co-ordinate
 * @input n1 : Integer array's ( X ) length
 * @input Y : Integer array corresponding to the Y co-ordinate
 * @input n2 : Integer array's ( Y ) length
 *
 * Points are represented by (X[i], Y[i])
 * 
 * @Output Integer
 *
 */
int coverPoints(int* x, int n1, int* y, int n2) {
    int i=0,maxi=0;
    for(i=0;i<max(n1,n2)-1;i++){
         maxi+=max(abs(x[i+1]-x[i]),abs(y[i+1]-y[i]));
    }
    return maxi;
}

int max( int a ,int b){
    if(a>b)
        return a;
    else 
        return b;
}

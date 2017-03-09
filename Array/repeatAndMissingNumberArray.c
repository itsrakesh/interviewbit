class Solution:
    # @param A : tuple of integers
    # @return a list of integers
    def repeatedNumber(self, A):
        A=list(A)
        r=list()
        numberSum=0
        totalSum=len(A)*(len(A)+1)/2
        for i in range(len(A)):
            numberSum+=A[i];
        for i in range(len(A)):
            if(A[abs(A[i])-1]<0):
                #print("totalsum:",totalSum,"numberSum:",numberSum,"A[i]:",A[i],"A[A[i]]:",A[A[i]])
                r.append(abs(A[i]))
                r.append(totalSum -(numberSum -abs(A[i])))
                return r
            else:
                A[abs(A[i])-1]=-A[abs(A[i])-1]

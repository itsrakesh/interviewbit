class Solution:
    # @param A : list of integers
    # @return an integer
    def maxArr(self, A):
        maxp=maxn= -99999999999999
        minp=minn=9999999999999999
        for i in range(len(A)):
                
                if (A[i]-i) > maxn:
                    maxn = A[i]-i
                if (A[i]-i)<minn:
                    minn =A[i]-i
                if (A[i]+i) > maxp:
                    maxp = A[i]+i
                if (A[i]+i)<minp:
                    minp =A[i]+i 
        # print ("maxn:",maxn,"minn:",minn,"maxp:",maxp,"minp:",minp)            
        return max(abs(maxp-minp),abs(maxn-minn))


class Solution:
    # @param A : string
    # @return a list of integers
    def flip(self, A):
        maxSoFar = 0
        maxHere=0
        minIndex=0
        result =list()
        first=-1
        second=-1
        A=list(A)
        # print(len(A),"A[0]",A[0])
        for i in range (len(A)):
            A[i]= 1 if A[i]=='0' else -1
        for i in range (len(A)):        
            maxHere+=A[i]
            if(maxHere<0):
                maxHere=0
                minIndex=i+1
            if(maxHere>maxSoFar):
                maxSoFar=maxHere
                first=minIndex+1
                second=i+1
        if(first!=-1):
            result.append(first)
            result.append(second)
        return result
                

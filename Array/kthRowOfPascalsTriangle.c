class Solution:
    # @param A : integer
    # @return a list of integers
    def getRow(self, A):
        matrix=[[1]*(A+1) for i in range(A+1)]
         
        for i in range(A+1):
            row = []
            for j in range(i+1):
                if(j-1>=0 and i-1>=0 and i!=j):
                    row.append(matrix[i-1][j]+matrix[i-1][j-1])
                    matrix[i][j]= matrix[i-1][j]+matrix[i-1][j-1]
                else:
                    row.append(1)
        return row

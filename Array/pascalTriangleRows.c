class Solution:
    # @param A : integer
    # @return a list of list of integers
    def generate(self, A):
        matrix=[[1]*A for i in range(A)]
        result = [] 
        for i in range(A):
            row = []
            for j in range(i+1):
                if(j-1>=0 and i-1>=0 and i!=j):
                    row.append(matrix[i-1][j]+matrix[i-1][j-1])
                    matrix[i][j]= matrix[i-1][j]+matrix[i-1][j-1]
                else:
                    row.append(1)
            result.append(row)    
        return result

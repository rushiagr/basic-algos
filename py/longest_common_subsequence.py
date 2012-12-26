# Lowest common subsequence

def matprint(m):
    """prints matrix m"""
    for i in len(m):
        print str(m).replace(',',' ').replace('[', ' ').replace(']', ' ')
            

# Recursive, no data shared, very poor performance
def lcs_length(string1, string2):
    """Returns ONLY the length of Longest Common Subsequence, not the string"""
    if not string1 or not string2:
        return 0
    if string1[-1] == string2[-1]:
        return (1 + lcs_length(string1[:-1], string2[:-1]))
    else:
        return max(lcs_length(string1, string2[:-1]), 
                    lcs_length(string1[:-1], string2))
                    
                    
# Example case: lcs_length('agrmujahiddeen', 'muddinmuhammad') returns 5

def lcs_length2(str1, str2):
    x = len(str1)
    y = len(str2)
    matrix = [[0] * (y+1)] * (x+1)      # x by y matrix

    for j in range(1, y+1):
        for i in range(1, x+1):
            if str1[i-1] == str2[j-1]:
                matrix[i][j] = matrix[i-1][j-1] + 1
            else:
                matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j])
            print matrix
                
    return matrix[x][y]
    
#print lcs_length2('agrmujahiddeen', 'muddinmuhammadeen')
print lcs_length2('banana', 'taranaaa')

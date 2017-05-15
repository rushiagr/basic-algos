# Print a matrix in spiral form

def print_spiral(matrix):
    '''matrix is a list of list -- a 2-d matrix.'''
    first_row = 0
    last_row = len(matrix) - 1
    first_column = 0
    last_column = len(matrix[0]) - 1

    while True:
        # Print first row
        for col_idx in range(first_column, last_column + 1):
            print(matrix[first_row][col_idx])

        first_row += 1
        if first_row > last_row:
            return

        # Print last column
        for row_idx in range(first_row, last_row + 1):
            print(matrix[row_idx][last_column])

        last_column -= 1
        if last_column < first_column:
            return

        # Print last row, in reverse
        for col_idx in reversed(range(first_column, last_column + 1)):
            print(matrix[last_row][col_idx])

        last_row -= 1
        if last_row < first_row:
            return

        # Print first column, bottom to top
        for row_idx in reversed(range(first_row, last_row + 1)):
            print(matrix[row_idx][first_column])

        first_column += 1
        if first_column > last_column:
            return

if __name__ == '__main__':
    mat = [[1,2,3,4],
           [5,6,7,8],
           [9,10,11,12],
           [13,14,15,16]]
    print_spiral(mat)

# Given nxn matrix, can you place queens in such a way that they don't attack each other

# http://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/

def can_place(queens, x, y):
    ''' given queens, can you place another queen at (x,y)'''
    for qx, qy in queens:
        if qx == x or qy == y:
            return False
        elif qx - qy == x - y or qx + qy == x + y:
            return False
    return True

def place_queens(n, queens, col):
    if col >= n:
        print("queens can be placed:")
        print(queens)
        return True
    for i in range(n):
        if can_place(queens, i, col):
            queens.append((i, col))
            progress = place_queens(n, queens, col+1)
            if progress:
                return True
            queens.pop()
    return False

def place_queens_all(n, queens, col):
    if col >= n:
        print("queens can be placed:")
        print(queens)
        return True
    for i in range(n):
        if can_place(queens, i, col):
            queens.append((i, col))
            progress = place_queens_all(n, queens, col+1)
            queens.pop()
    return False

# NOTE: we can actually return queens, instead of just printing it. The
# function will return two values -- is_success and queens

place_queens(4, [], 0)
place_queens_all(4, [], 0)

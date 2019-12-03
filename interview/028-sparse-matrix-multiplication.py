def sparse_mat_mult(a, b):
    arow = len(a)
    acol = len(a[0])
    brow = len(b)
    bcol = len(b[0])
    c = [[0]*bcol for _ in range(arow)]
    for i in range(arow):
        for k in range(acol):
            if a[i][k] != 0:
                for j in range(bcol):
                    c[i][j] += a[i][k]*b[k][j]
    return c

a = [[1, 2], [3, 4]]
b = [[5, 6, 7], [8, 9, 10]]
print(sparse_mat_mult(a, b))

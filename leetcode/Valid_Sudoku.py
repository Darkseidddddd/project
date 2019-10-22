def isValidSudoku(board):
    i, j = 0, 0
    c = [[],[],[],[],[],[],[],[],[]]
    while i < 9:
        r = [[],[],[]]
        j = 0
        while j < 9:
            i_ = i
            b = []
            while i_ < i+3:
                j_ = j
                while j_ < j+3:
                    n = board[i_][j_]
                    if n != '.':
                        if n in b or n in r[i_%3] or n in c[j_]:
                            return False
                        b.append(n)
                        r[i_%3].append(n)
                        c[j_].append(n)
                    j_ += 1
                i_ += 1
            print(b)
            j += 3
        i += 3
    return True

def isValidSudoku_(board):
    dict1 = [{} for i in range(9)]
    dict2 = [{} for i in range(9)]
    dict3 = [{} for i in range(9)]
    for i in range(9):
        for j in range(9):
            if board[i][j] != '.':
                n = board[i][j]
                dict1[i][n] = dict1[i].get(n, 0) + 1
                dict2[j][n] = dict2[j].get(n, 0) + 1
                index = i//3*3 + j//3
                dict3[index][n] = dict3[index].get(n, 0) + 1
                if dict1[i][n] > 1 or dict2[j][n] > 1 or dict3[index][n] > 1:
                    return False
    return True

if __name__ == '__main__':
    board = [["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
    print(isValidSudoku_(board))
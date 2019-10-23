def solveSdk(board, dict1, dict2, dict3):
    for i in range(9):
        for j in range(9):
            if board[i][j] == '.':
                for k in range(1,10):
                    index = i//3*3 + j//3
                    if dict1[i].get(k,0) + dict2[j].get(k,0) + dict3[index].get(k,0)==0:
                        board[i][j] = str(k)
                        dict1[i][k] = 1
                        dict2[j][k] = 1
                        dict3[index][k] = 1
                        if solveSdk(board, dict1, dict2, dict3):
                            return True
                        else:
                            dict1[i][k] = 0
                            dict2[j][k] = 0
                            dict3[index][k] = 0
                    if k == 9:
                        board[i][j] = '.'
                        return False
    return True
def solveSudoku(board):
    """
    Do not return anything, modify board in-place instead.
    """
    dict1 = [{} for i in range(9)]
    dict2 = [{} for i in range(9)]
    dict3 = [{} for i in range(9)]
    for i in range(9):
        for j in range(9):
            if board[i][j] != '.':
                n = int(board[i][j])
                dict1[i][n] = dict1[i].get(n, 0) + 1
                dict2[j][n] = dict2[j].get(n, 0) + 1
                index = i//3*3 + j//3
                dict3[index][n] = dict3[index].get(n, 0) + 1
    solveSdk(board, dict1, dict2, dict3)

if __name__ == '__main__':
    board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
    solveSudoku(board)
    print(board)
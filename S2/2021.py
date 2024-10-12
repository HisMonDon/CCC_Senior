import sys
ans = 0
inputs = []
def convert_row (canvas, row_number, N):
    row_number = row_number - 1
    for x in range(N):
        if canvas[row_number][x] == 'B':
            canvas[row_number][x] = "G"
        else:
            canvas[row_number][x] = 'B'
    return canvas

def convert_column (canvas, column_number, M):
    column_number = column_number - 1
    for x in range(M):
        if canvas[x][column_number] == 'B':
            canvas[x][column_number] = 'G'
        else:
            canvas[x][column_number] = 'B'
    return canvas



scan = sys.stdin.readline
canvas =[]
M = int(scan())
N = int(scan())
K = int(scan())


for _ in range(M):
    canvas.append([])
    for a in range(N):
        canvas[_].append('B')

input_counts = {}
for _ in range(K):
    input_value = input()
    input_counts[input_value] = input_counts.get(input_value, 0) + 1

inputs = []
for key, value in input_counts.items():
    if value % 2 != 0:
        inputs.append(key)
for _ in range(len(inputs)):
    roworcolumn, number = inputs[_].split()
    number = int(number)
    if roworcolumn == 'R':
        canvas = convert_row(canvas, number, N)
    else:
        canvas = convert_column(canvas, number, M)
for i in range(len(canvas)):
    for y in range(len(canvas[i])):
        if canvas[i][y] == 'G':
            ans+=1
print(ans)

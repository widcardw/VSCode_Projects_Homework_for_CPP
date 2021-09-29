from collections import deque


def bfs(start):
    end = "12345678x"
    d = {start: 0}  # 该字典存放每个状态距离初始状态的距离
    q = deque()  # 存放将要验证的状态
    q.append(start)
    dx = [0, 1, 0, -1]  # 用于"x"上下左右移动
    dy = [1, 0, -1, 0]
    while q:
        t = q.popleft()
        distance = d[t]
        if t == end:
            return distance
        k = t.index('x')
        x = k // 3  # 字符串的索引转换成3x3矩阵后的坐标
        y = k % 3

        tl = list(t)  # 由于字符串不是不可变量，因而把字符串变为数组，用于交换字符串中的字符位置
        for i in range(4):  # "x"上下左右移动
            a = x + dx[i]
            b = y + dy[i]
            if a >= 0 and a < 3 and b >= 0 and b < 3:  # 若坐标未超出矩阵范围
                nk = a * 3 + b  # 3x3矩阵的坐标转换成字符串的索引
                tl[nk], tl[k] = tl[k], tl[nk]  # 交换字符串中的字符位置
                t = "".join(tl)
                if t not in d:  # 如果t这个状态是新状态(之前未出现过)
                    q.append(t)
                    d[t] = distance + 1
                tl[nk], tl[k] = tl[k], tl[nk]  # 还原现场
    return -1


start = input().replace(" ", "")
ans = bfs(start)
print(ans)

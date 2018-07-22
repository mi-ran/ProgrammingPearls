#!/usr/bin/python
def init(n):
    x = [i*10 for i in range(0, n)] 
    return x


def binarysearch(x, t, n):
    l = 0
    u = n - 1
    while l <= u:
        m = (l+u)//2
        if x[m] < t:
            l = m + 1
        elif x[m] == t:
            return m
        else:
            u = m - 1
    return -1


def scaffolding():
    while True:
        n, t = input().split()
        x = init(int(n))
        print('  %d' % (binarysearch(x, int(t), int(n))))


if __name__ == '__main__':
    scaffolding()


import re


# Задача E. Умножение
def task_multiply():
    first = input()
    second = input()

    if first[0] == '0' or second[0] == '0':
        print(0)
        return

    print(int(first) * int(second))


if __name__ == '__main__':
    pass

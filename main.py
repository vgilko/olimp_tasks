import re


# Задача E. Умножение
def task_multiply():
    first = input()
    second = input()

    if first[0] == '0' or second[0] == '0':
        print(0)
        return

    print(int(first) * int(second))


# Задача S. Шаблоны
def task_template():
    template = input()
    message = input()

    template = template.replace('?', r'([a-z]|\.){1}')
    template = template.replace('*', r'([a-z]|\.)*')

    pattern = re.compile(template)
    match = pattern.match(message)

    if match is None:
        print('NO')
    else:
        print('YES')


if __name__ == '__main__':
    task_template()

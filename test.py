def test1():
    # Path: test.py
    print('test1')
    return 1+1

def test2():
    # Path: test.py
    print("Test2")
    return 2+2


def main():
    n = test1()
    print(n)
    t = test2()
    print(t)


if __name__ == '__main__':
    main()

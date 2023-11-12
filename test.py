def tes1():
    # Path: test.py
    print('tes1')
    return 1+1

def tes2():
    # Path: test.py
    print("Test2")
    return 2+2


def main():
    n = tes1()
    print(n)
    t = tes2()
    print(t)

if __name__ == '__main__':
    main()

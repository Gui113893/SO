def tes1():
    # Path: test.py
    print('tes1')
    return 1+1

def tes2():
    # Path: test.py
    ...


def main():
    n = tes1()
    print(n)
    tes2()

if __name__ == '__main__':
    main()

def test1():
    # Path: test.py
    print('tes1')
    return 1+1

def test2():
    # Path: test.py
    print("Test2")


def main():
    n = test1()
    print(n)
    test2()

if __name__ == '__main__':
    main()

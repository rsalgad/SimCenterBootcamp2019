def fib(n):
    if n == 0 or n == 1:
        return 1
    an = fib(n-2) + fib(n-1)
    return an

# the actual execution stuff
for i in range(10):
    print("a_{} = {}".format(i, fib(i)))


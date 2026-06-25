# JU26625

# Anonymous functions & lambda expressions

# The core syntax difference:
# Python added lambda expressions in 1994 (v1.0) as anonymous single-expression functions
# Python lambdas are expression-only (lambda params: expr); simple than C++ lambdas but less control



# Example 1: double a number ......................................................................
print("\nDouble a number")
# With a normal function
def double(x):
    return 2 * x
print(f"With double(x) function: {double(5)}")
print(double.__name__)

# With a lambda expression
f = lambda x: 2 * x
print(f"With lambda f(x) function: {f(5)}")
print(f.__name__)



# Example 2: add two numbers ......................................................................

# With a normal function
def add(x, y):
    return x + y
print(f"With add(x, y) function: {add(2, 3)}")
print(add.__name__)

# With a lambda expression
f = lambda x, y: x + y
print(f"With lambda add(x, y) function: {f(2, 3)}")
print(f.__name__)



# Example 3: filter even numbers ..................................................................

# With a normal function
def is_even(x):
    return x % 2 == 0
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]
evens = list(filter(is_even, numbers))
print(f"With is_even(x) function: {evens}")

# With a lambda expression
evens = list(filter(lambda x: x % 2 == 0, numbers))
print(f"With lambda(x) function: {evens}")

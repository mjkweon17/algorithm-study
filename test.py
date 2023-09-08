# 함수 정의
def square(x):
    return x ** 2

# 리스트에 함수 적용
numbers = [1, 2, 3, 4, 5]
squared_numbers = map(square, numbers)

print(squared_numbers)
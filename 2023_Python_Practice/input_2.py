import sys

# 한 개의 정수 입력받을 때
num1 = int(sys.stdin.readline())
# int(): 이 함수를 빼면 개행문자까지 같이 입력 받아져서 제거해주는 과정을 거쳐야 함

# 정해진 개수의 정수를 한줄에 입력받을 때
a, b, c = map(int, sys.stdin.readline().split())
# map(): 반복 가능한 객체(리스트 등)에 대해 각각의 요소들을 지정된 함수로 처리해줌
# split(): 문자열을 나눠주는 함수. 괄호 안에 특정 값을 넣어주면 그 값을 기준으로 문자열을 나눔. 아무 값도 넣어주지 않으면 공백을 기준으로 나눔.

# 임의의 개수의 정수를 한줄에 입력받아 리스트에 저장할 때
data = list(map(int, sys.stdin.readline()))
# list(): 자료형을 리스트형으로 변환해줌

# 임의의 개수의 정수를 n줄 입력받아 2차원 리스트에 저장할 때
data1 = []
n = int(sys.stdin.readline())
for i in range(n):
    data.append(list(map(int, sys.stdin.readline().split())))

# 문자열 n 줄을 입력받아 리스트에 저장할 때
n1 = int(sys.stdin.readline())
data2 = [sys.stdin.readline().strip() for i in range(n1)]
# strip():문자열 맨 앞과 맨 끝의 공백문자를 제거


# 참고: https://velog.io/@yeseolee/Python-%ED%8C%8C%EC%9D%B4%EC%8D%AC-%EC%9E%85%EB%A0%A5-%EC%A0%95%EB%A6%ACsys.stdin.readline
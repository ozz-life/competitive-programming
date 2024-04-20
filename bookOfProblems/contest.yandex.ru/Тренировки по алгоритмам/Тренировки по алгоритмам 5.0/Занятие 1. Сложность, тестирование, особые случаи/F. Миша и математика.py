n = int(input())
nums = list(map(int, input().split()))

state = 'no_odd_summand'
ans = []

for num in nums:
    if state == 'no_odd_summand':
        if num % 2 == 0:
            ans.append('+')
        else:
            state = 'last_odd'
    elif state == 'last_odd':
        if num % 2 == 0:
            ans.append('+')
            state = 'multiply_even'
        else:
            ans.append('x')
    elif state == 'multiply_even':
        ans.append('x')

print(''.join(ans))
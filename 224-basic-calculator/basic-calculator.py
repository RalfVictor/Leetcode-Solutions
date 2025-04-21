class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        result = 0
        number = 0
        sign  = 1
        for i in range(len(s)):
            char = s[i]
            if char.isdigit():
                number = 10*number+int(char)
            elif char == '+':
                result += sign*number
                number = 0
                sign = 1
            elif char == '-':
                result += sign*number
                number = 0
                sign = -1
            elif char == '(':
                stack.append(result)
                stack.append(sign)
                result = 0
                sign = 1 
            elif char == ')':
                result +=sign*number
                number = 0
                result *= stack.pop()
                result += stack.pop()
        if number != 0:
            result += sign*number
        return result

#
#  UVa787 - Maximum Sub-sequence Product
#  How to solve it? Sequence is small. Just try all possible subsequence multiplications

while True:
	try:
		numbers = []
		num = [0]
		while(num[-1] != -999999):
			num = [int(n) for n in input().split()]
			numbers.extend(num)
		del numbers[-1]

		total_numbers = len(numbers)
		resp = -999999
		for i in range(0,total_numbers):
			for j in range (i,total_numbers):
				p = 1
				for k in range(i,j+1):
					p*=numbers[k]
				resp = max(resp,p)

		print (resp)
	except EOFError:
		break


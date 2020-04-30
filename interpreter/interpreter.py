import sys

inpfile = open('myprog.greet', 'r')

for line in inpfile:
	(command, number) = line.split()
	num_times = int(number)
	if num_times < 1:
		print('Error on line ???... number too small.')
		sys.exit()
	for i in range(num_times):
		print(command)

inpfile.close()


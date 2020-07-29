#!/usr/bin/python

import matplotlib.pyplot as plt
import sys
import math
import numpy as np

if __name__ == "__main__":

	data = np.loadtxt(open(sys.argv[1], "rb"))

	a = 0
	b = 1000000
	
	x_axis = data[:,1]

	plt.plot(data[:,1:1000])
	plt.grid(True)
	#plt.yscale('log')
	plt.show()

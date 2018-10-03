# -*- coding: utf-8 -*-
"""
Created on Mon Oct  1 18:11:29 2018

@author: carve
"""

def fib(n):
    fibarr = [0,1] + [0]*(n-1)
    for i in range(2,n+1):
        fibarr[i] = fibarr[i-1] + fibarr[i-2]
    print(fibarr)
    return fibarr[n]

fib(3)

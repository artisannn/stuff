# -*- coding: utf-8 -*-
import numpy as np
import array
import os 
"""
Редактор Spyder

Это временный скриптовый файл.
"""
print('Hi, spyder!')

mat = 2*np.eye(3,4) + np.eye(3,4,1)
print(mat.flatten().reshape(12,1))

filePath = 'C:/Users/carve/Downloads/signtask_ver4.0/images/00000178.tab'

a = array.array('h')
fs = os.path.getsize(filePath)
a.fromfile(open(filePath,'r+b'),fs//a.itemsize)
print(a)


#s = 'a3b4c2e10b1'
#with open('C:/Users/carve/Downloads/dataset_3363_21.txt','r') as f:
#    s = f.readline()
#    dstr = re.findall('\d+',s)
#    cstr = re.findall('[a-zA-Z]',s)
#    for i,c in enumerate(dstr):
#        print(int(c)*cstr[i],end='')
import re
out = str()        
with open('C:/Users/carve/Downloads/dataset_3363_2.txt','r') as f:
    s = f.readline()
    dstr = re.findall('\d+',s)
    cstr = re.findall('[a-zA-Z]',s)
    for i,c in enumerate(dstr):
        out += int(c)*cstr[i]
with open('C:/Users/carve/Downloads/dataset_3363_2_out.txt','w') as of:
    of.write(out)
#print(dstr)
#print(cstr)

#with open(filePath,'r+b') as file:
#    b = file.read()
#    print(b)
    





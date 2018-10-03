# -*- coding: utf-8 -*-
"""
Created on Sun Sep 30 14:03:56 2018

@author: carve
"""

def left_bound(lst, key):
    """ find left boundary of interval of occurrence
    Осонвная идея такова, ВСЕГДА возвращаем индекс предыдущего от искомого эл-та,
    даже если элемента нет в массиве, то взовращаем инд-с его соседа слева еслиб
    искомый существовал бы в массиве. Для этого берем искомый элемент, 
    если он ПРАВЕЕ серединного, то ищем в ПРАВОЙ части массиваа, иначе ищем в левой
    """
    right = len(lst)
    left = -1
    while right-left > 1:
        middle = (right+left)//2
        if key > lst[middle]:
            left = middle
        else:
            right = middle
    return left   
     
def right_bound(lst, key):
    """ find right boundary of interval of occurrence
    В данном случае берем искомый, если он НЕ ЛЕВЕЕ серединного, то ищем в
    в ПРАВОЙ части массива
    """
    right = len(lst)
    left = -1
    while right-left > 1:
        middle = (right+left)//2
        if key >= lst[middle]:
            left = middle
        else:
            right = middle
    return right

def bin_search(lst, key):
    """ Тут основная идея аткова: right_bound и left_bound возвращают идексы НЕ
    самих вхожений, а индексы ДО и ПОСЛЕ этого вхождения. Т.о. если разница между
    right_bound и left_bound равна 1(меньше не может быть), то элемента нет в 
    массиве, если разница больше 2, то икомого больше одного встречается
    """
    r = right_bound(lst, key)
    l = left_bound(lst, key)      
    if r - l > 1:
        print("it's exist!(%d) index: %d, occurrence count: %d " % (key,l+1,r-l-1))
    else:
        print("there is no such element: %d!" % (key))
        
lst = [0,0,0,0]

def test_rb(lst):
    for i in range(len(lst)):
        print("el-t:(%d)the right bound is %d" % (i,right_bound(lst,i)))

def test_lb(lst):
    for i in range(len(lst)):
        print("el-t:(%d)the left bound is %d" % (i,left_bound(lst,i)))
 
def test_bs(lst):
    for i in range(len(lst)):
        bin_search(lst,i)

test_bs(lst)
dir(list)


    
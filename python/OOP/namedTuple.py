# -*- coding: utf-8 -*-
"""
Created on Wed Oct 17 04:05:34 2018

@author: carve
"""

from collections import namedtuple
""" Тот случай когда хочешь импортнуть что-то но хочестя тянуть весь модуль
"""
Point = namedtuple("point","x y z")
""" x y z - это именованные элементы кортежа. Теперь к ним можно достучаться
так: A.x или А.у или print(A.x)
"""
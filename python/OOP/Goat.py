# -*- coding: utf-8 -*-
"""
Created on Wed Oct 17 03:25:14 2018

@author: carve
"""

class Goat:
    legs_number = 4
    def __init__(self,legs,weight):
        self.legs_number = legs
        self.weight = weight
    def __str__(self):
        """ Еще одтн способ сформировать строку аля printf(%...%...)
        Этот метод нужен для того чтоб класс вел себя нативнj, напрмер,
        его можно распечатать через print. Главное, вернуть хоть какую-нибудь
        строку
        """
        s = "weight = {}\
            legs = {}".format(self.weight,self.legs_number)
        return s
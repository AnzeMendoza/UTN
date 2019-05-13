#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Feb 22 14:49:54 2019

@author: andres
"""

import scipy.signal as sig
from mpl_toolkits.mplot3d import Axes3D
import pylab
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm
from splane import pzmap, grpDelay, bodePlot, convert2SOS
import math

plt.close('all')

ORDER = 2
RIPPLE = 2

w0 = 1
Q = 10
k = 1

Q_start = 0.6
Q_stop = 10
Q_step = 0.5

Q_values = np.arange(Q_start,Q_stop+Q_step,Q_step)

type = 'LP'
#type = 'HP'
#type = 'BP'

for Q in Q_values:

    numLP = [k] 
    numHP = [k,0,0]
    numBP = [0,k*w0/Q,0]
    den = [1,w0/Q,w0*w0]

    if (type=='LP'):
        num=numLP
    else:
        if(type=='HP'):
            num=numHP
        else:
            if(type=='BP'):
                num=numBP    
            else:
                num=0        

    myFilter = sig.TransferFunction(num,den)

    print('Poles:',myFilter.poles)
    print('Zeros:',myFilter.zeros)

    bodePlot(myFilter)
    
    pzmap(myFilter)


plt.rcParams.update({'font.size': 16})

plt.show()

SOSpolynomials = convert2SOS(myFilter)


#%%

plt.close('all')

w_start = 1
w_stop = 5
w_step = 1
Q = 2

w_values = np.arange(w_start,w_stop+w_step,w_step)

type = 'LP'
#type = 'HP'
#type = 'BP'

for w0 in w_values:

    numLP = [k*w0*w0] 
    numHP = [k,0,0]
    numBP = [0,k*w0/Q,0]
    den = [1,w0/Q,w0*w0]

    if (type=='LP'):
        num=numLP
    else:
        if(type=='HP'):
            num=numHP
        else:
            if(type=='BP'):
                num=numBP    
            else:
                num=0        

    myFilter = sig.TransferFunction(num,den)

    print('Poles:',myFilter.poles)
    print('Zeros:',myFilter.zeros)

    bodePlot(myFilter)
    
    pzmap(myFilter)
    SOSpolynomials = convert2SOS(myFilter)
    print(SOSpolynomials)

plt.rcParams.update({'font.size': 16})

plt.show()

SOSpolynomials = convert2SOS(myFilter)


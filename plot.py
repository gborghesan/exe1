#!/usr/bin/env python
# -*- coding: utf-8 -*-

#sudo apt-get install python-netcdf4 (or python3)

from netCDF4 import Dataset
import matplotlib.pyplot as plt

fh = Dataset('reports.nc', mode='r')
t=fh['TimeStamp'][:]
x=fh['source.outport_value'][:]

fh.close()
plt.plot(t,x)
plt.show()

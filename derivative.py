import numpy as np
import math
from matplotlib import pyplot as plt

def f(x):
  return x**(2.5) - math.e*x**(6.3)

def df(x):
  return 2.5*x**(1.5) - 6.3*(math.e)*x**(5.3)

def derivative(x,a):
  return df(a)*x + (f(a) - df(a)*a)

X =  [i/1000 for i in range(-1000, 1001,2)]
y =  [derivative(x, 0.8) for x in X]
yf = [f(x) for x in X]

plt.plot(X, yf)
plt.plot(X, y)
plt.show()

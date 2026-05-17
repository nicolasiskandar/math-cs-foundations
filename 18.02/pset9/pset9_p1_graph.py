import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter, MultipleLocator

a = 1
t = np.linspace(0, 4*np.pi, 1000)

x = a * (t - np.sin(t))
y = a * (1 - np.cos(t))

fig, ax = plt.subplots()
ax.plot(x, y)

ax.set_aspect('equal', adjustable='box')
ax.grid(True)

def pi_formatter(x, pos):
    n = x / np.pi
    if n == 0:
        return "0"
    elif n == 1:
        return r"$\pi$"
    elif n == -1:
        return r"$-\pi$"
    elif n.is_integer():
        return rf"${int(n)}\pi$"
    return rf"${n:.1f}\pi$"

ax.xaxis.set_major_locator(MultipleLocator(np.pi))
ax.xaxis.set_major_formatter(FuncFormatter(pi_formatter))

plt.show()

fig.savefig('./pset9_p1_graph.png')

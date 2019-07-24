from numpy import array, linspace, pi, sin, cos, tan
import matplotlib.pyplot as plt

valList = linspace(-pi, pi, 100)

plt.plot(valList, sin(valList), label = "sin(x)")
plt.plot(valList, cos(valList), label = "cos(x)")
plt.plot(valList, tan(valList), label = "tan(x)")

plt.title("Trigonometric Differences")

plt.xlabel("x in radians")

plt.ylim([-3,3])
plt.xlim([-pi,pi])

plt.legend(loc='upper right')

plt.show()



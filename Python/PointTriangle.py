import math

class Point:
    x = 0
    y = 0
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y
    def input(self):
        print("INPUT X AND Y COORDINATES OF A POINT")
        x = input("Enter x: ")
        y = input("Enter y: ")
        self.x = float(x)
        self.y = float(y)
    def output(self):
        print("OUTPUT X AND Y COORDINATES OF A POINT")
        print("x = " + str(self.x) + "; y = " + str(self.y))
    def set_values(self, x, y):
        self.x = x
        self.y = y
    def distanceTo(self, other):
        aX = float(other.x)
        bX = float(self.x)
        aY = float(other.y)
        bY = float(self.y)
        return math.sqrt((aX - bX) * (aX - bX) + (aY - bY) * (aY - bY))
    def distanceToOx(self):
        return self.y
    def distanceToOy(self):
        return self.x

class Triangle():
    A = Point()
    B = Point()
    C = Point()
    AB = 0
    BC = 0
    CA = 0
    def input(self):
        print("INPUT X AND Y COORDINATES FOR 3 POINTS OF THE TRIANGLE")
        print("Input point A")
        self.A.input()
        print("Input point B")
        self.B.input()
        print("Input point C")
        self.C.input()
        self.AB = self.A.distanceTo(self.B)
        self.BC = self.B.distanceTo(self.C)
        self.CA = self.C.distanceTo(self.A)
    def output(self):
        print("OUTPUT X AND Y COORDINATES FOR 3 POINTS OF THE TRIANGLE")
        print("Output point A")
        self.A.output()
        print("Output point B")
        self.B.output()
        print("Output point C")
        self.C.output()
    def isValidTriangle(self):
        if self.A.x <= 0 or self.A.y <= 0 or self.B.x <= 0 or self.B.y <= 0 or self.C.x <= 0 or self.C.y <=0:
            return False
        if (self.A.x == self.B.x and self.B.x == self.C.x) or (self.A.y == self.B.y and self.B.y == self.C.y):
            return False
        if (self.AB + self.BC > self.CA and self.BC + self.CA > self.AB and self.CA + self.AB > self.BC):
            return True
        else:
            return False
    def TriangleType(self):
        #0: no special features, 1: isosceles, 2: right, 3: isosceles & right, 4: equilateral
        isosceles = False
        right = False
        equilateral = False
        if not self.isValidTriangle():
            return -1
        if self.AB == self.BC or self.BC == self.CA:
            isosceles = True
        if self.AB == self.BC and self.BC == self.CA:
            equilateral = True
        if self.AB * self.AB + self.BC * self.BC - self.CA * self.CA == 0 or self.BC * self.BC + self.CA * self.CA - self.AB * self.AB == 0 or self.CA * self.CA + self.AB * self.AB - self.BC * self.BC == 0:
            right = True
        if (not isosceles) and (not right):
            return 0
        elif isosceles and (not right) and (not equilateral):
            return 1
        elif (not isosceles) and right and (not equilateral):
            return 2
        elif isosceles and right and (not equilateral):
            return 3
        else:
            return 4
    def perimeter(self):
        if not self.isValidTriangle():
            return 0
        else:
            return self.AB + self.BC + self.CA
    def area(self):
        if not self.isValidTriangle():
            return 0
        else:
            p = self.perimeter() / 2
            result = math.sqrt(p * (p - self.AB) * (p - self.BC) * (p - self.CA))
            return result
    def G(self):
        center = Point()
        center.x = (self.A.x + self.B.x + self.C.x) / 3
        center.y = (self.A.y + self.B.y + self.C.y) / 3
        return center

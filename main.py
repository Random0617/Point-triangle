from PointTriangle import Point
from PointTriangle import Triangle

A = Point()
B = Point()
print("Input point A:")
A.input()
print("Input point B:")
B.input()
print("Output point A:")
A.output()
print("Output point B:")
B.output()
print("Distance from point A to point B: " + str(A.distanceTo(B)))
print("Distance from point A to Ox: " + str(A.distanceToOx()))
print("Distance from point A to Oy: " + str(A.distanceToOy()))
print("Distance from point B to Ox: " + str(B.distanceToOx()))
print("Distance from point B to Oy: " + str(B.distanceToOy()))

ABC = Triangle()
print("Input triangle ABC:")
ABC.input()
print("Output triangle ABC:")
ABC.output()
triangle_type = "unknown"
if ABC.TriangleType() == -1:
    triangle_type = "This is not a valid triangle."
elif ABC.TriangleType() == 0:
    triangle_type = "normal triangle"
elif ABC.TriangleType() == 1:
    triangle_type = "isosceles triangle"
elif ABC.TriangleType() == 2:
    triangle_type = "right triangle"
elif ABC.TriangleType() == 3:
    triangle_type = "isosceles & right triangle"
else:
    triangle_type = "equilateral"
print("Triangle type: " + str(triangle_type))
print("Perimeter: " + str(ABC.perimeter()))
print("Area: " + str(ABC.area()))
print("Center G: (" + str(ABC.G().x) + ", " + str(ABC.G().y) + ")")
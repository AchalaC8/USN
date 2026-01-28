/*A class called MyPoint, which models a 2D point with x and y coordinates, is designed as follows:
● Two instance variables x (int) and y (int).
● A default (or "no-arg") constructor that construct a point at the default location of (0, 0).
● A overloaded constructor that constructs a point with the given x and y coordinates.
● A method setXY() to set both x and y.
● A method getXY() which returns the x and y in a 2-element int array.
● A toString() method that returns a string description of the instance in the format "(x, y)".
● A method called distance(int x, int y) that returns the distance from this point to another point at the given (x, y) coordinates
● An overloaded distance(MyPoint another) that returns the distance from this point to the given MyPoint instance (called another)
● Another overloaded distance() method that returns the distance from this point to the origin (0,0)
Develop the code for the class MyPoint. Also develop a JAVA program (called TestMyPoint) to test all the methods defined in the class.*/


//1. MyPoint.java
public class MyPoint {
// Instance variables private int x; private int y;
// Default constructor (0, 0)
public MyPoint() {
this.x = 0;
this.y = 0;
}
// Overloaded constructor with parameters
public MyPoint(int x, int y) {
this.x = x;
this.y = y;
}
// Setter method to set both x and y public void setXY(int x, int y) { this.x = x;
this.y = y;
}
// Getter method that returns x and y in an array
public int[] getXY() {
return new int[] { x, y };
}
// toString method
public String toString() {
return "(" + x + ", " + y + ")";
}
// Method to calculate distance to another point with (x, y)
public double distance(int x, int y) {
int dx = this.x - x;
int dy = this.y - y;
return Math.sqrt(dx * dx + dy * dy);
}
// Overloaded distance method to another MyPoint object
public double distance(MyPoint another) {
int dx = this.x - another.x;
int dy = this.y - another.y;
return Math.sqrt(dx * dx + dy * dy);
}
// Overloaded distance method to the origin (0, 0)
public double distance() {
return Math.sqrt(x * x + y * y);
}
}


//2. TestMyPoint.java
public class TestMyPoint {
public static void main(String[] args) {
// Create points
  MyPoint p1 = new MyPoint(); // Default (0,0) MyPoint p2 = new MyPoint(3, 4); // (3,4)
// Test toString() System.out.println("p1: " + p1); // (0, 0)
System.out.println("p2: " + p2); // (3, 4)
// Test setXY() p1.setXY(5, 6);
System.out.println("After setXY, p1: " + p1); // (1, 2)
// Test getXY()
int[] coords = p1.getXY();
System.out.println("p1 x: " + coords[0] + ", y: " + coords[1]);
// Test distance(x, y)
double d1 = p1.distance(4, 6); System.out.println("Distance from p1 to (4,6): " + d1);
// Test distance(MyPoint another)
double d2 = p1.distance(p2); System.out.println("Distance from p1 to p2: " + d2);
// Test distance() to origin
double d3 = p2.distance(); System.out.println("Distance from p2 to origin: " + d3);
}
}

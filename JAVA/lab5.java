/*Develop a JAVA program to create a class named shape. Create three sub classes namely: circle, triangle and square, 
  each class has two member functions named draw () and erase (). 
  Demonstrate polymorphism concepts by developing suitable methods, defining member data and main program.*/
// Base class class Shape {
void draw() { System.out.println("Drawing Shape");
}
void erase() { System.out.println("Erasing Shape");
}
}
// Subclass Circle
class Circle extends Shape { void draw() {
System.out.println("Drawing Circle");
}
void erase() { System.out.println("Erasing Circle");
}
}
// Subclass Triangle
class Triangle extends Shape { void draw() {
System.out.println("Drawing Triangle");
}
void erase() { System.out.println("Erasing Triangle");
}
}
// Subclass Square
class Square extends Shape { void draw() {
System.out.println("Drawing Square");
  }
void erase() { System.out.println("Erasing Square");
}
}
// Main class to demonstrate polymorphism
public class ShapeDemo {
public static void main(String[] args) {
// Create shape references pointing to different objects Shape shape;
shape = new Circle(); shape.draw(); shape.erase();
shape = new Triangle(); shape.draw(); shape.erase();
shape = new Square(); shape.draw(); shape.erase();
}
}

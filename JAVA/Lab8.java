// Outer class 
class Outer { 
void display() {
System.out.println("This is the outer class display method.");
}
// Inner class 
class Inner { 
void display() {
System.out.println("This is the inner class display method.");
}
}
}
// Main class
public class OuterInnerTest {
public static void main(String[] args) {
// Create outer class object 
Outer outer = new Outer();
outer.display(); // Call outer class display
// Create inner class object using outer class object 
Outer.Inner inner = outer.new Inner(); 
inner.display(); // Call inner class display
}
}

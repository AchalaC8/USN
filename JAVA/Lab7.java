// Interface Resizable
interface Resizable {
void resizeWidth(int width);
void resizeHeight(int height);
}
// Rectangle class implementing Resizable
class Rectangle implements Resizable { 
int width;
int height;
// Constructor 
Rectangle(int w, int h) { 
width = w;
height = h;
}
// Method to display current width and height
void display() {
System.out.println("Width: " + width + ", Height: " + height);
}
// Implement resizeWidth method
public void resizeWidth(int newWidth) { 
width = newWidth;
}
// Implement resizeHeight method
public void resizeHeight(int newHeight) { 
height = newHeight;
}
}

// Main class
public class ResizeTest {
public static void main(String[] args) {
// Create rectangle object
Rectangle rect = new Rectangle(10, 20); 
System.out.println("Original Size:"); 
rect.display();
// Resize width and height 
rect.resizeWidth(30); 
rect.resizeHeight(40); 
System.out.println("Resized Size:"); 
rect.display();
  }

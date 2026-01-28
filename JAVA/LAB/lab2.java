/*2. Develop a stack class to hold a maximum of 10 integers with suitable methods. Develop a JAVA main method to illustrate Stack operations.*/
import java.util.Scanner;
// Stack class
class Stack {
private int maxSize = 10; // Maximum stack size
private int[] stackArray;
private int top;
// Constructor
public Stack() {
stackArray = new int[maxSize]; top = -1;
}
// Push method
public void push(int value) {
if (top == maxSize - 1) {
System.out.println("Stack Overflow! Cannot push " + value);
} else {
stackArray[++top] = value; System.out.println(value + " pushed to stack.");
}
}
// Pop method public int pop() { if (top == -1) {
System.out.println("Stack Underflow! Stack is empty.");
return -1;
} else {
int value = stackArray[top--]; System.out.println(value + " popped from stack.");
return value;
}
}
// Display method public void display() { if (top == -1) {
System.out.println("Stack is empty.");
} else {
System.out.println("Stack elements are (Top to Bottom):"); for (int i = top; i >= 0; i--) { System.out.println(stackArray[i]);
}
}
}
}
// Main class
public class StackDemo {
public static void main(String[] args) { Stack stack = new Stack();
Scanner sc = new Scanner(System.in);
int choice, value;
do {
System.out.println("\n==== Stack Operations Menu ===="); System.out.println("1. Push");
System.out.println("2. Pop"); System.out.println("3. Display"); System.out.println("4. Exit"); System.out.print("Enter your choice (1-4): "); choice = sc.nextInt();
switch (choice) {
case 1:
System.out.print("Enter value to push: ");
value = sc.nextInt(); stack.push(value); break;
case 2:
stack.pop(); break; case 3:
stack.display();
break; case 4:
System.out.println("Exiting the program...");
break; default:
System.out.println("Invalid choice! Please enter between 1 to 4.");
}
} while (choice != 4); sc.close();
}
}
  

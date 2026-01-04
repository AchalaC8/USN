/*Develop a JAVA program to create a package named mypack and import & implement it in a 
suitable class.
✅ Step 1: Create the Package (mypack)
File: mypack/Message.java*/
package mypack; // Declare package name
// Class inside the package 
public class Message { 
public void display() {
System.out.println("Hello from mypack!");
}
}

/*✅ Step 2: Create the Main Class to Use the Package 
File: TestPackage.java*/
import mypack.Message; // Import the class from mypack
public class TestPackage {
public static void main(String[] args) { 
Message msg = new Message(); 
msg.display();
}
}

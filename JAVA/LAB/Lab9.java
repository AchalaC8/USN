/*Develop a JAVA program to raise a custom exception (user defined exception) for Division 
By Zero using try, catch, throw and finally.*/
// Custom Exception class
class DivisionByZeroException extends Exception {
// Constructor 
DivisionByZeroException(String message) { 
super(message);
}
}
// Main class
public class DivisionTest {
public static void main(String[] args) {
int num = 10;
int den = 0; // Deliberately setting denominator to zero
try {
if (den == 0) {
throw new DivisionByZeroException("Division by zero is not allowed!");
}
int result = num / den; 
System.out.println("Result: " + result);
}
catch (DivisionByZeroException e) { 
System.out.println("Exception Caught: " + e.getMessage());
}
finally {
System.out.println("Finally block executed.");
}
}
}

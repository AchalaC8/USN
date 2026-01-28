/*3. A class called Employee, which models an employee with an ID, name and salary, is designed as shown in the following class diagram. 
The method raise Salary (percent) increases the salary by the given percentage.
  Develop the Employee class and suitable main method for demonstration.*/
import java.util.Scanner;
// Employee class class Employee { private int id; private String name;
private double salary;
// Constructor to initialize employee details
public Employee(int id, String name, double salary) {
this.id = id; this.name = name; this.salary = salary;
}
// Method to display employee details
public void display() {
System.out.println(" ");
System.out.println("Employee ID : " + id); System.out.println("Employee Name : " + name); System.out.println("Employee Salary: ₹" + salary); System.out.println(" ");
}
// Method to raise salary by a given percentage
public void raiseSalary(double percent) {
if (percent > 0) {
double increment = salary * percent / 100; salary += increment;
System.out.println("Salary increased by " + percent + "% (₹" + increment + ")");
} else {
System.out.println("Invalid percentage. Salary not changed.");
}
}
}
// Main class
public class EmployeeDemo {
public static void main(String[] args) { Scanner sc = new Scanner(System.in);
// Input employee details System.out.print("Enter Employee ID: "); int id = sc.nextInt();
sc.nextLine(); // Clear input buffer System.out.print("Enter Employee Name: "); String name = sc.nextLine(); System.out.print("Enter Employee Salary: "); double salary = sc.nextDouble();
// Create Employee object
Employee emp = new Employee(id, name, salary);
// Display initial details
System.out.println("\n--- Employee Details Before Salary Raise ---"); emp.display();
// Input raise percentage
System.out.print("\nEnter percentage to raise salary: ");
double percent = sc.nextDouble();
// Apply raise emp.raiseSalary(percent);
// Display updated details
System.out.println("\n--- Employee Details After Salary Raise ---"); emp.display();
sc.close();
}
}

/*Develop a program to create a class MyThread in this class a constructor, call the base class constructor, using super and start the thread. The run method of the class starts after this. It can be observed that both main thread and created child thread are executed concurrently.*/
class MyThread1 extends Thread { MyThread1() {
super("ChildThread"); // Call Thread class constructor to set thread name start(); // Start the thread
}
public void run() {
for (int i = 1; i <= 5; i++) { System.out.println(getName() + ": " + i); try {
Thread.sleep(500); // Pause for 500 milliseconds
} catch (Exception e) { System.out.println(e);
}
}
}
}
public class ThreadExample {
public static void main(String[] args) {
MyThread1 t = new MyThread1(); // Create and start child thread
// Main thread work
for (int i = 1; i <= 5; i++) { System.out.println("Main Thread: " + i); try {
Thread.sleep(500); // Pause for 500 milliseconds
} catch (Exception e) { System.out.println(e);
}
}
  }
}

/*Write a program to illustrate creation of threads using runnable class. (start method start each of the newly created thread. Inside the run method there is sleep() for suspend the thread for 500 milliseconds).*/
// Create a class that implements Runnable class MyThread implements Runnable { String threadName;
// Constructor MyThread(String name) { threadName = name;
}
// The run method contains the code that runs in the thread
public void run() {
for (int i = 1; i <= 5; i++) { System.out.println(threadName + " - Count: " + i); try {
Thread.sleep(500); // Suspend thread for 500 milliseconds
} catch (InterruptedException e) { System.out.println(threadName + " interrupted.");
}
}
System.out.println(threadName + " finished.");
}
}
// Main class
public class RunnableThreadExample {
public static void main(String[] args) {
// Create Runnable objects
MyThread t1 = new MyThread("Thread-1"); MyThread t2 = new MyThread("Thread-2");
// Create Thread objects with Runnable Thread thread1 = new Thread(t1);
  Thread thread2 = new Thread(t2);
// Start the threads thread1.start(); thread2.start();
}
}

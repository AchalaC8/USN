/*1. Develop a JAVA program to add TWO matrices of suitable order N (The value of N should be read from command line arguments.*/
import java.util.Scanner; public class MatrixAddition {
public static void main(String[] args) { Scanner sc = new Scanner(System.in);
// Input for matrix size N
System.out.print("Enter the order N of the matrices: "); int n = sc.nextInt();
int[][] matrix1 = new int[n][n];
int[][] matrix2 = new int[n][n];
int[][] result = new int[n][n];
// Input for first matrix
System.out.println("Enter elements for Matrix 1:"); for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) { System.out.print("Element [" + i + "][" + j + "]: "); matrix1[i][j] = sc.nextInt();
}
}
// Input for second matrix System.out.println("Enter elements for Matrix 2:"); for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) { System.out.print("Element [" + i + "][" + j + "]: "); matrix2[i][j] = sc.nextInt();
}
}
// Adding the matrices for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
result[i][j] = matrix1[i][j] + matrix2[i][j];
}
}
// Displaying the result
System.out.println("\nResultant Matrix after Addition:"); for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) { System.out.print(result[i][j] + "\t");
}
System.out.println();
}
sc.close();
}
}

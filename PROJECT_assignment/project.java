import java.util.Scanner;

public class InfixPostfixEvaluation {

    static final int MAX = 100;

    // ---------- Stack for infix to postfix ----------
    static char[] opStack = new char[MAX];
    static int opTop = -1;

    // ---------- Stack for postfix evaluation ----------
    static int[] valStack = new int[MAX];
    static int valTop = -1;

    // ---------- Operator Stack Methods ----------
    static void pushOp(char ch) {
        opStack[++opTop] = ch;
    }

    static char popOp() {
        return opStack[opTop--];
    }

    static int precedence(char ch) {
        switch (ch) {
            case '#': return -1;
            case '(':
            case ')': return 0;
            case '+':
            case '-': return 1;
            case '*':
            case '/':
            case '%': return 2;
            case '^': return 3;
        }
        return -1;
    }

    // ---------- Infix to Postfix ----------
    static String infixToPostfix(String infix) {
        char[] postfix = new char[MAX];
        int j = 0;

        pushOp('#');

        for (int i = 0; i < infix.length(); i++) {
            char symbol = infix.charAt(i);

            if (Character.isDigit(symbol)) {
                postfix[j++] = symbol;
            }
            else if (symbol == '(') {
                pushOp(symbol);
            }
            else if (symbol == ')') {
                char temp = popOp();
                while (temp != '(') {
                    postfix[j++] = temp;
                    temp = popOp();
                }
            }
            else {
                while (precedence(opStack[opTop]) >= precedence(symbol)) {
                    postfix[j++] = popOp();
                }
                pushOp(symbol);
            }
        }

        while (opTop > 0) {
            postfix[j++] = popOp();
        }

        return new String(postfix, 0, j);
    }

    // ---------- Value Stack Methods ----------
    static void pushVal(int val) {
        valStack[++valTop] = val;
    }

    static int popVal() {
        return valStack[valTop--];
    }

    static int power(int base, int exp) {
        int result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }

    // ---------- Postfix Evaluation ----------
    static int evaluatePostfix(String postfix) {

        for (int i = 0; i < postfix.length(); i++) {
            char ch = postfix.charAt(i);

            if (Character.isDigit(ch)) {
                pushVal(ch - '0');
            }
            else {
                int val2 = popVal();
                int val1 = popVal();
                int result = 0;

                switch (ch) {
                    case '+': result = val1 + val2; break;
                    case '-': result = val1 - val2; break;
                    case '*': result = val1 * val2; break;
                    case '/': result = val1 / val2; break;
                    case '%': result = val1 % val2; break;
                    case '^': result = power(val1, val2); break;
                }
                pushVal(result);
            }
        }
        return popVal();
    }

    // ---------- Main ----------
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter infix expression (single-digit operands): ");
        String infix = sc.next();

        String postfix = infixToPostfix(infix);
        int result = evaluatePostfix(postfix);

        System.out.println("Infix Expression   : " + infix);
        System.out.println("Postfix Expression : " + postfix);
        System.out.println("Evaluation Result  : " + result);

        sc.close();
    }
                  }

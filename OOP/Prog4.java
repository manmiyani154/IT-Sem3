public class Prog4 {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide a number.");
            return;
        }

        int n = Integer.parseInt(args[0]);
        long fact = 1;

        for (int i = 1; i <= n; i++) {
            fact *= i;
        }

        System.out.println("Factorial: " + fact);
    }
}

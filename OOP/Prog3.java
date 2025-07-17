import java.util.Scanner;

public class Prog3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String special = "$#%";
        System.out.print("Enter password: ");
        String pass = sc.nextLine();

        boolean hasUpper = false, hasDigit = false, hasSpecial = false;

        if (pass.length() >= 8) {
            for (char ch : pass.toCharArray()) {
                if (Character.isUpperCase(ch)) hasUpper = true;
                else if (Character.isDigit(ch)) hasDigit = true;
                else if (special.indexOf(ch) != -1) hasSpecial = true;
            }
        }

        if (hasUpper && hasDigit && hasSpecial && pass.length() >= 8)
            System.out.println("Password is Valid");
        else
            System.out.println("Password is Invalid");
    }
}

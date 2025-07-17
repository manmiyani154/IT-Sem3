import java.util.Scanner;

class Student {
    int roll_no;
    String name, address, branch;

    void getData(Scanner sc) {
        roll_no = sc.nextInt();
        name = sc.next();
        address = sc.next();
        branch = sc.next();
    }

    void showData() {
        System.out.println(roll_no + " " + name + " " + address + " " + branch);
    }
}

public class Prog9 {
    public static void branchDisplay(Student[] s) {
        for (Student stu : s) {
            if (stu.branch.equalsIgnoreCase("computer"))
                stu.showData();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Student[] s = new Student[3];

        for (int i = 0; i < s.length; i++) {
            s[i] = new Student();
            s[i].getData(sc);
        }

        branchDisplay(s);
    }
}

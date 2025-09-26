import java.util.Scanner;

class Student {
    int roll_no;
    String name;
    String address;
    String branch;

    void getData() {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter Roll No: ");
        roll_no = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter Name: ");
        name = sc.nextLine();
        System.out.print("Enter Address: ");
        address = sc.nextLine();
        System.out.print("Enter Branch: ");
        branch = sc.nextLine();
    }

    void showData() {
        System.out
                .println("\nRoll No: " + roll_no + "\nName: " + name + "\nAddress: " + address + "\nBranch: " + branch);
    }

    static void branchDisplay(Student[] s) {
        System.out.println("\n--- Students of Computer Branch ---");
        for (Student st : s) {
            if (st.branch.equalsIgnoreCase("Computer")) {
                st.showData();
            }
        }
    }
}

class Prog9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of students: ");
        int n = sc.nextInt();
        Student[] arr = new Student[n];

        for (int i = 0; i < n; i++) {
            arr[i] = new Student();
            arr[i].getData();
        }

        System.out.println("\n--- All Students ---");
        for (Student st : arr) {
            st.showData();
        }

        Student.branchDisplay(arr);
    }
}

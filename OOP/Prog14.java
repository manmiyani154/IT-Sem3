import java.util.Scanner;

interface Shape3 {
    double PI = 3.14159;

    void read();

    void show();
}

class Rectangle3 implements Shape3 {
    double length, breadth;

    public void read() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter length: ");
        length = sc.nextDouble();
        System.out.print("Enter breadth: ");
        breadth = sc.nextDouble();
    }

    public void show() {
        System.out.println("Area of Rectangle: " + (length * breadth));
    }
}

class Circle3 implements Shape3 {
    double radius;

    public void read() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter radius: ");
        radius = sc.nextDouble();
    }

    public void show() {
        System.out.println("Area of Circle: " + (PI * radius * radius));
    }
}

class Prog14 {
    public static void main(String[] args) {
        Shape3 s;

        s = new Rectangle3();
        s.read();
        s.show();

        s = new Circle3();
        s.read();
        s.show();
    }
}

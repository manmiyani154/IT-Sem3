interface Shape {
    double PI = 3.1415;
    void read();
    void show();
}

class Rectangle implements Shape {
    double l, b;
    public void read() {
        l = 4;
        b = 5;
    }
    public void show() {
        System.out.println("Rectangle Area: " + (l * b));
    }
}

class Circle implements Shape {
    double r;
    public void read() {
        r = 3;
    }
    public void show() {
        System.out.println("Circle Area: " + (PI * r * r));
    }
}

public class Prog14 {
    public static void main(String[] args) {
        Shape s1 = new Rectangle();
        Shape s2 = new Circle();
        s1.read();
        s1.show();
        s2.read();
        s2.show();
    }
}

abstract class Shape {
    double a, b;
    Shape(double x, double y) {
        a = x;
        b = y;
    }
    abstract double area();
}

class Rectangle extends Shape {
    Rectangle(double x, double y) {
        super(x, y);
    }
    double area() {
        return a * b;
    }
}

class Triangle extends Shape {
    Triangle(double x, double y) {
        super(x, y);
    }
    double area() {
        return 0.5 * a * b;
    }
}

public class Prog13 {
    public static void main(String[] args) {
        Shape s1 = new Rectangle(4, 5);
        Shape s2 = new Triangle(3, 6);
        System.out.println("Rectangle area: " + s1.area());
        System.out.println("Triangle area: " + s2.area());
    }
}

class Shape {
    double a, b;

    Shape(double x, double y) {
        a = x;
        b = y;
    }

    double area() {
        return 0;
    }
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

public class Prog12 {
    public static void main(String[] args) {
        Rectangle r = new Rectangle(4, 5);
        Triangle t = new Triangle(3, 6);
        System.out.println("Rectangle area: " + r.area());
        System.out.println("Triangle area: " + t.area());
    }
}

class Shape {
    double dim1, dim2;

    Shape(double d1, double d2) {
        dim1 = d1;
        dim2 = d2;
    }

    double area() {
        return 0;
    }
}

class Rectangle extends Shape {
    Rectangle(double d1, double d2) {
        super(d1, d2);
    }

    double area() {
        return super.dim1 * super.dim2;
    }
}

class Triangle extends Shape {
    Triangle(double d1, double d2) {
        super(d1, d2);
    }

    double area() {
        return 0.5 * super.dim1 * super.dim2;
    }
}

class Prog12 {
public static void main(String[] args) {
Rectangle r = new Rectangle(10, 5);
Triangle t = new Triangle(8, 6);


System.out.println("Area of Rectangle: " + r.area());
System.out.println("Area of Triangle: " + t.area());
}

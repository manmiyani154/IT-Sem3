abstract class Shape2 {
    double dim1, dim2;

    Shape2(double d1, double d2) {
        dim1 = d1;
        dim2 = d2;
    }

    abstract double area();
}

class Rectangle2 extends Shape2 {
    Rectangle2(double d1, double d2) {
        super(d1, d2);
    }

    double area() {
        return dim1 * dim2;
    }
}

class Triangle2 extends Shape2 {
    Triangle2(double d1, double d2) {
        super(d1, d2);
    }

    double area() {
        return 0.5 * dim1 * dim2;
    }
}

class Prog13 {
    public static void main(String[] args) {
        Shape2 s;

        s = new Rectangle2(5, 10);
        System.out.println("Area of Rectangle: " + s.area());

        s = new Triangle2(6, 8);
        System.out.println("Area of Triangle: " + s.area());
    }
}

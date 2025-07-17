public class Prog5 {
    double a = 1, b = 1, c = 1;

    Prog5() {}

    Prog5(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }

    double getPerimeter() {
        return a + b + c;
    }

    double getArea() {
        double s = getPerimeter() / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    public static void main(String[] args) {
        Prog5 t = new Prog5(3, 4, 5);
        System.out.println("Area: " + t.getArea());
        System.out.println("Perimeter: " + t.getPerimeter());
    }
}

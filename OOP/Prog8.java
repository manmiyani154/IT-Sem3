public class Prog8 {
    int real, img;

    Prog8() {}

    Prog8(int real, int img) {
        this.real = real;
        this.img = img;
    }

    Prog8 add(Prog8 c) {
        return new Prog8(this.real + c.real, this.img + c.img);
    }

    void display() {
        System.out.println(real + " + " + img + "i");
    }

    public static void main(String[] args) {
        Prog8 c1 = new Prog8(3, 4);
        Prog8 c2 = new Prog8(1, 2);
        Prog8 c3 = c1.add(c2);
        c3.display();
    }
}

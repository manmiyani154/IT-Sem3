import java.util.Scanner;

public class Prog7 {
    private int hour, minute;

    Prog7() {}

    Prog7(int h, int m) {
        hour = h;
        minute = m;
    }

    void getTime() {
        Scanner sc = new Scanner(System.in);
        hour = sc.nextInt();
        minute = sc.nextInt();
    }

    void ahead(Prog7 t) {
        if (hour > t.hour || (hour == t.hour && minute > t.minute))
            System.out.println("This time is ahead.");
        else
            System.out.println("Other time is ahead.");
    }

    Prog7 add(Prog7 t) {
        int h = hour + t.hour;
        int m = minute + t.minute;
        h += m / 60;
        m %= 60;
        return new Prog7(h, m);
    }

    void showTime() {
        System.out.println(hour + " hrs " + minute + " mins");
    }

    public static void main(String[] args) {
        Prog7 t1 = new Prog7(2, 45);
        Prog7 t2 = new Prog7(1, 30);
        Prog7 t3 = t1.add(t2);
        t3.showTime();
        t1.ahead(t2);
    }
}

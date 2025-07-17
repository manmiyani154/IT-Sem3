public class Prog10 {
    static int count = 0;

    Prog10() {
        count++;
    }

    static void displayCount() {
        System.out.println("Objects created: " + count);
    }

    public static void main(String[] args) {
        Prog10 a = new Prog10();
        Prog10 b = new Prog10();
        Prog10 c = new Prog10();
        displayCount();
    }
}

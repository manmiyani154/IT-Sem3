class Even extends Thread {
    public void run() {
        for (int i = 0; i <= 10; i += 2)
            System.out.println("Even: " + i);
    }
}

class Odd extends Thread {
    public void run() {
        for (int i = 1; i < 10; i += 2)
            System.out.println("Odd: " + i);
    }
}

public class Prog18 {
    public static void main(String[] args) {
        Even e = new Even();
        Odd o = new Odd();
        e.start();
        o.start();
    }
}

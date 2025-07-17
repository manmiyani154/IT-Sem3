class Shared {
    int data;
    boolean produced = false;

    synchronized void produce(int value) throws InterruptedException {
        while (produced) wait();
        data = value;
        System.out.println("Produced: " + data);
        produced = true;
        notify();
    }

    synchronized void consume() throws InterruptedException {
        while (!produced) wait();
        System.out.println("Consumed: " + data);
        produced = false;
        notify();
    }
}

public class Prog19 {
    public static void main(String[] args) {
        Shared s = new Shared();

        Thread producer = new Thread(() -> {
            try {
                for (int i = 1; i <= 5; i++) {
                    s.produce(i);
                }
            } catch (InterruptedException e) {}
        });

        Thread consumer = new Thread(() -> {
            try {
                for (int i = 1; i <= 5; i++) {
                    s.consume();
                }
            } catch (InterruptedException e) {}
        });

        producer.start();
        consumer.start();
    }
}

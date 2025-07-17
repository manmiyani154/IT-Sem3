public class Prog6 {
    private long startTime;
    private long endTime;

    Prog6() {
        startTime = System.currentTimeMillis();
    }

    void start() {
        startTime = System.currentTimeMillis();
    }

    void stop() {
        endTime = System.currentTimeMillis();
    }

    long getElapsedTime() {
        return endTime - startTime;
    }

    public static void main(String[] args) throws InterruptedException {
        Prog6 sw = new Prog6();
        Thread.sleep(1000);
        sw.stop();
        System.out.println("Elapsed time: " + sw.getElapsedTime() + " ms");
    }
}


class Counter {
    int count = 0;

    // this will ensure that only 1 thread works with the function at a time
    public synchronized void increment() {
        count++;
    }
}

public class RaceCondition {
    public static void main(String[] args) throws InterruptedException {
        Counter c = new Counter();

        Runnable obj1 = () -> {
            for (int i = 1; i <= 10000; i++) {
                c.increment();
            }
        };
        Runnable obj2 = () -> {
            for (int i = 1; i <= 10000; i++) {
                c.increment();
            }
        };

        Thread t1 = new Thread(obj1);
        Thread t2 = new Thread(obj2);

        // t1.start() and t2.start() → threads start asynchronously.
        // Main thread does NOT wait
        t1.start();
        t2.start();

        // both the threads will join the main thread and only then the program will
        // proceed
        t1.join();
        t2.join();

        System.out.println("after 2 threads complete -- " + c.count);
    }
}
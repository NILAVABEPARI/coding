class ThreadClass1 extends Thread {
    @Override
    public void run() {
        for (int i = 0; i < 100; i++) {
            System.out.println("hi");
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class ThreadClass2 extends Thread {
    @Override
    public void run() {
        for (int i = 0; i < 100; i++) {
            System.out.println("hello");
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class Threads {
    public static void main(String[] args) {

        // thread priority ranges from 1 to 10 (5 is default priority)
        ThreadClass1 obj1 = new ThreadClass1();
        ThreadClass2 obj2 = new ThreadClass2();

        System.out.println("priority obj1 -- " + obj1.getPriority());
        System.out.println("priority obj2 -- " + obj2.getPriority());

        obj1.setPriority(Thread.MAX_PRIORITY);
        obj2.setPriority(Thread.MAX_PRIORITY - 1);

        obj1.start();
        try {
            Thread.sleep(5);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        obj2.start();
    }
}

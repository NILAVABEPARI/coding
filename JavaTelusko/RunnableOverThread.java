// class Runnable1 implements Runnable {
//     @Override
//     public void run() {
//         for (int i = 1; i <= 5; i++) {
//             System.out.println("hi");
//             try {
//                 Thread.sleep(10);
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//         }
//     }
// }

// class Runnable2 implements Runnable {
//     @Override
//     public void run() {
//         for (int i = 1; i <= 5; i++) {
//             System.out.println("hello");
//             try {
//                 Thread.sleep(10);
//             } catch (InterruptedException e) {
//                 e.printStackTrace();
//             }
//         }
//     }
// }

// public class RunnableOverThread {
//     public static void main(String[] args) {
//         Runnable obj1 = new Runnable1();
//         Runnable obj2 = new Runnable2();

//         // in case of runnable we need to create separate thread objects and then use
//         // .start() on them
//         Thread t1 = new Thread(obj1);
//         Thread t2 = new Thread(obj2);

//         t1.start();
//         t2.start();
//     }
// }

// !! simplification of the above code
public class RunnableOverThread {
    public static void main(String[] args) {
        // by using anonymous inner class and lambda expression we can reduce the code
        // to a great extent
        Runnable obj1 = () -> {
            for (int i = 1; i <= 5; i++) {
                System.out.println("hi2");
                try {
                    Thread.sleep(10);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };
        Runnable obj2 = () -> {
            for (int i = 1; i <= 5; i++) {
                System.out.println("hello2");
                try {
                    Thread.sleep(10);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        // in case of runnable we need to create separate thread objects and then use
        // .start() on them
        Thread t1 = new Thread(obj1);
        Thread t2 = new Thread(obj2);

        t1.start();
        t2.start();
    }
}
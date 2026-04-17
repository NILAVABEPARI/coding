@java.lang.FunctionalInterface
// !! Functional Interface is an interface that has only pure one abstract
// method.
interface A3 {
    void show(int i);
}

public class FunctionalInterface {
    public static void main(String[] args) {
        // using anonymous inner class
        A3 obj = new A3() {
            @Override
            public void show(int i) {
                System.out.println("inside show " + i);
            }
        };
        obj.show(5);

        // using lambda expression --
        // lambda expression works with only functional interface
        // we are writing 1 line hence no {}
        A3 obj2 = i -> System.out.println("inside show lambda " + i);
        obj2.show(10);
    }
}

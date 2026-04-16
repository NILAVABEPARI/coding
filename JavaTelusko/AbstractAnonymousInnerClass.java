abstract class A2 {
    public abstract void show2();

    public abstract void config();
}

public class AbstractAnonymousInnerClass {
    public static void main(String[] args) {
        // we are not creating an object of abstract class.
        // we are creating an object of anonymous inner class
        A2 obj = new A2() {
            @Override
            public void show2() {
                System.out.println("inside new show function of AbstractAnonymousInnerClass");
            }

            @Override
            public void config() {
                System.out.println("inside config function of AbstractAnonymousInnerClass");
            }
        };
        obj.show2();
    }
}

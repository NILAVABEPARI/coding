class Outer {
    private int age = 25;

    public void show() {
        System.out.println(age + " inside show");
    }

    // !! member inner class
    class Inner {
        public void config() {
            System.out.println(age + " inside config");
        }
    }

    static class StaticInner {
        public void config2() {
            // here age cannot be accessed because it is non static
            System.out.println("inside config2");
        }
    }
}

public class InnerClass {
    public static void main(String[] args) {
        Outer out = new Outer();
        out.show();

        Outer.Inner in = out.new Inner();
        in.config();

        Outer.StaticInner in2 = new Outer.StaticInner();
        in2.config2();
    }
}

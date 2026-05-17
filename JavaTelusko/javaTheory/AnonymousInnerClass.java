class A1 {
    public void show1() {
        System.out.println("inside show");
    }
}

public class AnonymousInnerClass {
    public static void main(String[] args) {
        A1 obj = new A1() {
            @Override
            public void show1() {
                System.out.println("inside new show function");
            }
        };
        obj.show1();
    }
}

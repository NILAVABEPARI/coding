class A {
    public void show1() {
        System.out.println("in A show");
    }
}

class B extends A {
    public void show2() {
        System.out.println("in B show");
    }
}

public class UpCasting_DownCasting {
    public static void main(String[] args) {
        A obj = new B(); // !! UpCasting
        obj.show1();

        B obj2 = (B) obj; // !! DownCasting
        obj2.show2();
    }
}

// !! if we write a class as final then it will stop inheritance and the class
// !! cannot be inherited further
class Calc { // final class Calc
    // !! by making a method final -- it will stop overriding the method further
    public void show() { // public final void show()
        System.out.println("By nilava");
    }

    public void add(int x, int y) {
        System.out.println(x + y);
    }
}

class AdvanceCalc extends Calc {
    @Override
    public void show() {
        System.out.println("By panda");
    }
}

public class Final {
    public static void main(String[] args) {
        final int num = 9;
        // num = 9; -- final variable is constant and its value can't be changed
        System.out.println(num);

        Calc obj = new Calc();
        obj.show();
        obj.add(4, 5);
    }
}

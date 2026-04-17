@java.lang.FunctionalInterface
interface ADD {
    int add(int i, int j);
}

public class LambdaExpression {
    public static void main(String[] args) {
        ADD obj = (i, j) -> i + j;
        int result = obj.add(10, 20);
        System.out.println("result -- " + result);
    }
}

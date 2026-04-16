public class WrapperClass {
    public static void main(String[] args) {
        // In the below example we are taking a primitive value and storing it in an
        // object. This is called boxing
        int num = 7;
        Integer num1 = new Integer(num); // boxing
        Integer num2 = num; // autoBoxing

        int num3 = num2.intValue(); // unboxing
        int num4 = num2; // auto-unboxing

    }
}
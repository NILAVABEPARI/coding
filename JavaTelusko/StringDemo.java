public class StringDemo {

    public static void main(String[] args) {
        // String name = "nilava";
        // name = name + " bepari";
        // System.out.println("hello " + name);

        // String s1 = "Nilava";
        // String s2 = "Nilava";
        // System.out.println(s1 == s2); // true

        StringBuffer emptyName = new StringBuffer();
        System.out.println(emptyName.capacity()); // by default it gives an empty buffer of 16;

        StringBuffer name = new StringBuffer("nilava");
        System.out.println(name.capacity()); // 16 + 6 = 22;
        System.out.println(name.length()); // 6;

        // !! NOTE: StringBuffer is thread safe and StringBuilder is not.
    }
}
class Mobile {
    String brand; // instance variable
    int price; // instance variable
    static String name;

    /*
     * the static block is called only once, when the class is loaded in jvm for
     * the first time and it is called before the constructor
     */
    static {
        System.out.println("-------- inside static block --------");
        name = "Phone";
    }

    public Mobile() {
        brand = "";
        price = 200;
        // name = "phone"; // it does not make sense to initialize the static variable
        // every time an object is created
    }

    public void show() {
        System.out.println(brand + " : " + price + " : " + name);
        // a static variable can be accessed inside a non-static method
    }

    public static void show1(Mobile obj) {
        System.out.println("---- inside static method ----");
        // System.out.println(brand + " : " + price + " : " + name);
        // this line will give an error because we cant directly use non-static
        // variables
        // inside a static method

        System.out.println(obj.brand + " : " + obj.price + " : " + name);
    }
}

public class Static {
    public static void main(String[] args) throws ClassNotFoundException {
        Mobile obj1 = new Mobile();
        obj1.brand = "Apple";
        obj1.price = 50000;
        Mobile.name = "SmartPhone";

        Mobile obj2 = new Mobile();
        obj2.brand = "Samsung";
        obj2.price = 60000;

        obj1.show();
        obj2.show();

        Mobile.show1(obj1);
        Mobile.show1(obj2);

        // !! If we want to load a class but not create an object from it --
        Class.forName("Mobile");
    }
}

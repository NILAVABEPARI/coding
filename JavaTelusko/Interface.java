interface inter {
    // by default variables are final and static
    int age = 25;
    String location = "Kolkata";

    // by default methods are public and abstract
    void show4();

    void config2();
};

class imp implements inter {
    @Override
    public void show4() {
        System.out.println("inside show");
    }

    @Override
    public void config2() {
        System.out.println("inside config");
    }
}

public class Interface {
    public static void main(String[] args) {
        inter obj = new imp();
        obj.show4();
        obj.config2();
        System.out.println(imp.age);
        System.out.println(imp.location);
    }
}

enum Laptop {
    Macbook(2000), XPS(2200), ThinkPad(1500), Surface;

    private int price;

    // !! we are creating private constructors because we are creating objects
    // inside the enum class
    private Laptop() {
        this.price = 500;
    }

    private Laptop(int price) {
        this.price = price;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

}

public class EnumClass {
    public static void main(String[] args) {
        for (Laptop lap : Laptop.values()) {
            System.out.println(lap + " : " + lap.getPrice());
        }
    }
}

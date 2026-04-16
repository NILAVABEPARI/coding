class laptop {
    int price;
    String model;

    // own toString method --
    // @Override
    // public String toString() {
    // this function will override the toString of Object class
    // return "from to string method";
    // }

    // auto generated toString method --
    @Override
    public String toString() {
        return "laptop [price=" + price + ", model=" + model + "]";
    }

    // right click inside class --> source action -->
    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + price;
        result = prime * result + ((model == null) ? 0 : model.hashCode());
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        laptop other = (laptop) obj;
        if (price != other.price)
            return false;
        if (model == null) {
            if (other.model != null)
                return false;
        } else if (!model.equals(other.model))
            return false;
        return true;
    }
}

public class ObjectClass {
    public static void main(String[] args) {
        laptop obj = new laptop();
        obj.model = "Lenovo Yoga";
        obj.price = 1000;

        laptop obj2 = new laptop();
        obj2.model = "Lenovo Yoga";
        obj2.price = 1000;

        // !! toString method is a method inside Object class
        System.out.println(obj); // by default this line calls the toString method of class

        boolean result = obj.equals(obj2);
        System.out.println(result);
    }
}

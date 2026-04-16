enum STATUS {
    Running, Failed, Pending, Success
}

public class Enums {
    public static void main(String[] args) {
        STATUS[] ss = STATUS.values();

        for (STATUS s : ss) {
            // ordinal gives the index of enums
            System.out.println(s + " : " + s.ordinal());
        }
    }
}

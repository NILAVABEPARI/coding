// ! Class implementing Eager Loading
class EagerSingleton {
    /*
     * final - cannot be changed or reassigned after initialization
     * static - belongs to the class rather than the object
     * there is only one instance of the class and it is created when the class is
     * loaded
     */
    private static final EagerSingleton instance = new EagerSingleton();

    // private constructor
    private EagerSingleton() {
        // Declaring it private prevents creation of its object using the new keyword
    }

    // Method to get the instance of class
    public static EagerSingleton getInstance() {
        return instance; // Always returns the same instance
    }
}

public class EagerSingletonPattern {
    public static void main(String[] args) {
        EagerSingleton eagerSingleton = EagerSingleton.getInstance();
        System.out.println("object pointer -- " + eagerSingleton);
    }
}
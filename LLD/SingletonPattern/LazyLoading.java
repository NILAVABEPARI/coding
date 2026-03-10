// ! Class implementing Lazy Loading
// ! This is not thread safe
class LazySingleton {
    // Object declaration -- null initially
    private static LazySingleton instance;

    // private constructor
    private LazySingleton() {
        // ! Declaring it private prevents creation of its object using the new keyword
    }

    // Method to get the instance of class
    public static LazySingleton getInstance() {
        // If the instance is null, create a new instance
        if (instance == null) {
            instance = new LazySingleton();
        }
        // Return the instance -- if it is not null, return the same instance
        return instance;
    }
}

// ! Class implementing Lazy Loading -- Thread Safe
class LazySingletonThreadSafe {
    private static LazySingletonThreadSafe instance;

    private LazySingletonThreadSafe() {
        // Declaring it private prevents creation of its object using the new keyword
    }

    // ! synchronized - ensures that only one thread can access the method at a time
    public static synchronized LazySingletonThreadSafe getInstance() {
        if (instance == null) {
            instance = new LazySingletonThreadSafe();
        }
        return instance;
    }
}

// ! Class implementing Lazy Loading -- Double Checked Locking
class LazySingletonDoubleCheckedLocking {
    /*
     * volatile - ensures that the instance is not cached in the thread local
     * memory and is always read from the main memory
     * Prevents instruction reordering -- ensures that the object is
     * initialized before it is returned.
     * 
     * Instruction Reordering --------------------------------------------------
     * Creating an object in Java is not a single step. Internally it happens in 3
     * steps:
     * 1. Allocate memory for the object
     * 2. Initialize the object
     * 3. Set the instance variable to the object
     * 
     * Normally the order should be: 1 -> 2 -> 3
     * If the instruction reordering happens, the object may be returned before it
     * is initialized. This can happen in the following ways:
     * 1. 1 -> 3 -> 2
     * 2. 2 -> 1 -> 3
     * 3. 2 -> 3 -> 1
     * 4. 3 -> 1 -> 2
     * 5. 3 -> 2 -> 1
     * This is why we need to use the volatile keyword.
     * 
     * Instruction reordering improves CPU performance by allowing independent
     * instructions to execute out of order while preserving single-threaded
     * correctness. Problems only arise in multithreaded environments without proper
     * memory visibility guarantees.
     */
    private static volatile LazySingletonDoubleCheckedLocking instance;

    private LazySingletonDoubleCheckedLocking() {
    }

    @SuppressWarnings("DoubleCheckedLocking")
    public static LazySingletonDoubleCheckedLocking getInstance() {
        if (instance == null) {
            synchronized (LazySingletonDoubleCheckedLocking.class) {
                if (instance == null) {
                    instance = new LazySingletonDoubleCheckedLocking();
                }
            }
        }
        return instance;
    }
}

// ! Class implementing Lazy Loading -- Static Inner Class
class LazySingletonStaticInnerClass {
    private LazySingletonStaticInnerClass() {
    }

    // ! Static inner class is loaded only when it is referenced
    // ! This is thread safe
    private static class LazySingletonHolder {
        private static final LazySingletonStaticInnerClass instance = new LazySingletonStaticInnerClass();
    }

    public static LazySingletonStaticInnerClass getInstance() {
        return LazySingletonHolder.instance;
    }
}

public class LazyLoading {
    public static void main(String[] args) {
        LazySingleton lazySingleton = LazySingleton.getInstance();
        System.out.println("object pointer -- " + lazySingleton);
    }
}

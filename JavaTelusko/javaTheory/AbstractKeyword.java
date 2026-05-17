/*
    * Characteristics of Java Abstract Keyword
    * Abstract classes cannot be instantiated
    * Abstract methods do not have a body
    * Abstract classes can have both abstract and concrete methods
    * Abstract classes can have constructors
    * Abstract classes can contain instance variables
    * Abstract classes can implement interfaces

    !! The following are various illegal combinations of other modifiers for methods with respect to abstract modifiers: 
        * final
        * abstract native
        * abstract synchronized
        * abstract static
        * abstract private
        * abstract strict
*/

abstract class A {
    abstract void m1();

    void m2() {
        System.out.println("This is a concrete method.");
    }
}

class B extends A {
    @Override
    void m1() {
        System.out.println("B's implementation of m1.");
    }
}

public class AbstractKeyword {
    public static void main(String[] args) {
        B b = new B();
        b.m1();
        b.m2();
    }
}
package org.example;

public class Alien {
    private int age;
    private Laptop lap;

    public Alien() {
        System.out.println("Alien Constructor called");
    }

    public Alien(int age, Laptop lap) {
        System.out.println("Alien parameterized Constructor called");
        this.age = age;
        this.lap = lap;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        System.out.println("Setter called");
        this.age = age;
    }

    public Laptop getLap() {
        return lap;
    }

    public void setLap(Laptop lap) {
        this.lap = lap;
    }

    public void code() {
        System.out.println("Coding!!!");
        lap.compile();
    }
}

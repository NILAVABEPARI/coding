import java.util.*;

// Represents a customizable Burger Meal
class BurgerMeal {
    // Required components
    private final String bunType;
    private final String patty;

    // optional components
    private final boolean hasCheese;
    private final List<String> toppings;
    private final String side;
    private final String drink;

    // private constructor to force use of Builder
    private BurgerMeal(BurgerBuilder builder) {
        this.bunType = builder.bunType;
        this.patty = builder.patty;
        this.hasCheese = builder.hasCheese;
        this.toppings = builder.toppings;
        this.side = builder.side;
        this.drink = builder.drink;
    }

    // Static nested Builder Class
    public static class BurgerBuilder {
        // Required
        private final String bunType;
        private final String patty;

        // Optional
        private boolean hasCheese;
        private List<String> toppings;
        private String side;
        private String drink;

        // builder constructor with required fields
        public BurgerBuilder(String bunType, String patty) {
            this.bunType = bunType;
            this.patty = patty;
        }

        // Method to set cheese
        public BurgerBuilder withCheese(boolean hasCheese) {
            this.hasCheese = hasCheese;
            return this;
        }

        // Method to set toppings
        public BurgerBuilder withToppings(List<String> toppings) {
            this.toppings = toppings;
            return this;
        }

        // Method to set side
        public BurgerBuilder withSide(String side) {
            this.side = side;
            return this;
        }

        // Method to set drink
        public BurgerBuilder withDrink(String drink) {
            this.drink = drink;
            return this;
        }

        // Final build method
        public BurgerMeal build() {
            return new BurgerMeal(this);
        }
    }

    @Override
    public String toString() {
        return "BurgerMeal{" +
                "bunType='" + bunType + '\'' +
                ", patty='" + patty + '\'' +
                ", hasCheese=" + hasCheese +
                ", toppings=" + toppings +
                ", side=" + side +
                ", drink=" + drink +
                '}';
    }
}

public class BuilderPattern {
    public static void main(String[] args) {
        // Creating burger with only required fields
        BurgerMeal plainBurger = new BurgerMeal.BurgerBuilder("wheat", "veg").build();

        // Burger with cheese only
        BurgerMeal burgerWithCheese = new BurgerMeal.BurgerBuilder("wheat", "veg").withCheese(true).build();

        // Fully loaded burger
        List<String> toppings = Arrays.asList("lettuce", "onion", "jalapeno");
        BurgerMeal loadedBurger = new BurgerMeal.BurgerBuilder("multigrain", "chicken")
                .withCheese(true)
                .withToppings(toppings)
                .withSide("fries")
                .withDrink("coke")
                .build();

        System.out.println(plainBurger);
        System.out.println(burgerWithCheese);
        System.out.println(loadedBurger);
    }
}

/*
 * main()
 * |
 * | new BurgerBuilder
 * v
 * Builder Object
 * |
 * | optional setters
 * v
 * Builder Updated
 * |
 * | build()
 * v
 * BurgerMeal Object
 */
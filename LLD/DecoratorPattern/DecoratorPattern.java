// Component Interface 
interface Pizza {
    String getDescription();

    double getCost();
}

// Concrete Component: Base Class
class PlainPizza implements Pizza {
    @Override
    public String getDescription() {
        return "Plain Pizza";
    }

    @Override
    public double getCost() {
        return 150.00;
    }
}

// Concrete Component: Base Class
class MargheritaPizza implements Pizza {
    @Override
    public String getDescription() {
        return "MargheritaPizza";
    }

    @Override
    public double getCost() {
        return 200.00;
    }
}

// Abstract Decorator
// Implements Pizza and holds a reference to a Pizza object
abstract class PizzaDecorator implements Pizza {
    protected Pizza pizza;

    public PizzaDecorator(Pizza pizza) {
        this.pizza = pizza;
    }
}

// Concrete Decorator: Adds Extra Cheese
class ExtraCheese extends PizzaDecorator {
    public ExtraCheese(Pizza pizza) {
        super(pizza);
    }

    @Override
    public String getDescription() {
        return pizza.getDescription() + ", Extra Cheese";
    }

    @Override
    public double getCost() {
        return pizza.getCost() + 40.0;
    }
}

// Concrete Decorator: Adds Olives
class Olives extends PizzaDecorator {
    public Olives(Pizza pizza) {
        super(pizza);
    }

    @Override
    public String getDescription() {
        return pizza.getDescription() + ", Olives";
    }

    @Override
    public double getCost() {
        return pizza.getCost() + 30.0;
    }
}

public class DecoratorPattern {
    public static void main(String[] args) {
        Pizza myPizza = new PlainPizza();

        myPizza = new ExtraCheese(myPizza);
        myPizza = new Olives(myPizza);

        System.out.println("Pizza description -- " + myPizza.getDescription());
        System.out.println("Cost -- " + myPizza.getCost());
    }
}
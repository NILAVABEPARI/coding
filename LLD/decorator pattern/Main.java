// component interface 
interface Pizza {
    String getDescription();
    double getCost();
}

// base class
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

abstract class PizzaDecorator implements Pizza {
    protected Pizza pizza;

    public PizzaDecorator(Pizza pizza) {
        this.pizza = pizza;
    }
}

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
        return pizza.getCost()+ 30.0;
    }
}

public class Main {
    public static void main(String []args) {
        Pizza myPizza = new PlainPizza();

        myPizza = new ExtraCheese(myPizza);
        myPizza = new Olives(myPizza);

        System.out.println("Pizza description -- " + myPizza.getDescription());
        System.out.println("Cost -- " + myPizza.getCost());
    }
}
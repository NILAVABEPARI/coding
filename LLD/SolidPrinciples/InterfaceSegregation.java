import java.util.Arrays;
import java.util.List;

interface IVegMenu {
    List<String> getVegMenu();
}

interface INonVegMenu {
    List<String> getNonVegMenu();
}

interface IDrinksMenu {
    List<String> getDrinksMenu();
}

class VegMenu implements IVegMenu {
    @Override
    public List<String> getVegMenu() {
        return Arrays.asList("Veg Curry", "Paneer", "Dal");
    }
}

class NonVegMenu implements INonVegMenu {
    @Override
    public List<String> getNonVegMenu() {
        return Arrays.asList("Mutton", "Chicken", "Egg");
    }
}

class DrinksMenu implements IDrinksMenu {
    @Override
    public List<String> getDrinksMenu() {
        return Arrays.asList("Coke", "Lassi", "Water");
    }
}

class MenuDisplay {
    public static void displayVegMenu(IVegMenu menu) {
        System.out.println("Veg Menu:");
        for (String item : menu.getVegMenu()) {
            System.out.println("- " + item);
        }
    }

    public static void displayNonVegMenu(INonVegMenu menu) {
        System.out.println("Non Veg Menu:");
        for (String item : menu.getNonVegMenu()) {
            System.out.println("- " + item);
        }
    }

    public static void displayDrinksMenu(IDrinksMenu menu) {
        System.out.println("Drinks Menu:");
        for (String item : menu.getDrinksMenu()) {
            System.out.println("- " + item);
        }
    }
}

public class InterfaceSegregation {
    public static void main(String[] args) {
        VegMenu vegMenu = new VegMenu();
        NonVegMenu nonVegMenu = new NonVegMenu();
        DrinksMenu drinksMenu = new DrinksMenu();

        MenuDisplay.displayVegMenu(vegMenu);
        MenuDisplay.displayNonVegMenu(nonVegMenu);
        MenuDisplay.displayDrinksMenu(drinksMenu);
    }
}
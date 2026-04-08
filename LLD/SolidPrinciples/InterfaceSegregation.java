import java.util.Arrays;
import java.util.List;
// !! Lists are like vectors in C++

interface IMenu {
    List<String> getMenu();
}

// Veg menu implementation
class VegMenu implements IMenu {
    @Override
    public List<String> getMenu() {
        return Arrays.asList("Veg Curry", "Paneer", "Dal");
    }
}

// Non-Veg menu implementation
class NonVegMenu implements IMenu {
    @Override
    public List<String> getMenu() {
        return Arrays.asList("Mutton", "Chicken", "Egg");
    }
}

// Drinks menu implementation
class DrinksMenu implements IMenu {
    @Override
    public List<String> getMenu() {
        return Arrays.asList("Coke", "Lassi", "Water");
    }
}

class MenuDisplay {
    public static void displayMenu(IMenu menu, String menuType) {
        System.out.println("Menu Type: " + menuType);
        for (String item : menu.getMenu()) {
            System.out.println("- " + item);
        }
        System.out.println();
    }
}

public class InterfaceSegregation {
    public static void main(String[] args) {
        VegMenu vegMenu = new VegMenu();
        NonVegMenu nonVegMenu = new NonVegMenu();
        DrinksMenu drinksMenu = new DrinksMenu();

        MenuDisplay.displayMenu(vegMenu, "veg menu");
        MenuDisplay.displayMenu(nonVegMenu, "non veg menu");
        MenuDisplay.displayMenu(drinksMenu, "drinks menu");
    }
}
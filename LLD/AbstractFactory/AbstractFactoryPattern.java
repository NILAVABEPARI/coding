// abstract product
interface Button {
    void paint();

    void onClick();
}

// abstract product
interface Checkbox {
    void paint();

    void onSelect();
}

// concrete product
class WindowsButton implements Button {
    @Override
    public void paint() {
        System.out.println("Painting a Windows-style button.");
    }

    @Override
    public void onClick() {
        System.out.println("Windows button clicked.");
    }
}

// concrete product
class WindowsCheckbox implements Checkbox {
    @Override
    public void paint() {
        System.out.println("Painting a Windows-style checkbox.");
    }

    @Override
    public void onSelect() {
        System.out.println("Windows checkbox selected.");
    }
}

// concrete product
class MacOSButton implements Button {
    @Override
    public void paint() {
        System.out.println("Painting a macOS-style button.");
    }

    @Override
    public void onClick() {
        System.out.println("macOS button clicked.");
    }
}

// concrete product
class MacOSCheckbox implements Checkbox {
    @Override
    public void paint() {
        System.out.println("Painting a macOS-style checkbox.");
    }

    @Override
    public void onSelect() {
        System.out.println("macOS checkbox selected.");
    }
}

// abstract factory
interface GUIFactory {
    Button createButton();

    Checkbox createCheckbox();
}

// concrete factory
class WindowsFactory implements GUIFactory {
    @Override
    public Button createButton() {
        return new WindowsButton();
    }

    @Override
    public Checkbox createCheckbox() {
        return new WindowsCheckbox();
    }
}

// concrete factory
class MacOSFactory implements GUIFactory {
    @Override
    public Button createButton() {
        return new MacOSButton();
    }

    @Override
    public Checkbox createCheckbox() {
        return new MacOSCheckbox();
    }
}

// client
class Application {
    /*
     * final - cannot be changed or reassigned after initialization
     */
    private final Button button;
    private final Checkbox checkbox;

    public Application(GUIFactory factory) {
        this.button = factory.createButton();
        this.checkbox = factory.createCheckbox();
    }

    public void renderUI() {
        button.paint();
        checkbox.paint();

        button.onClick();
        checkbox.onSelect();
    }
}

class FactoryProvider {
    public static GUIFactory getFactory(String os) {
        if (os.contains("Windows"))
            return new WindowsFactory();
        return new MacOSFactory();
    }
}

public class AbstractFactoryPattern {
    public static void main(String[] args) {
        // Simulate platform detection
        String os = System.getProperty("os.name");
        System.out.println("System -- " + os);
        GUIFactory factory = FactoryProvider.getFactory(os);

        Application app = new Application(factory);
        app.renderUI();
    }
}

/*
 * Abstract Products
 * ↓
 * Concrete Products
 * ↓
 * Abstract Factory
 * ↓
 * Concrete Factories
 * ↓
 * Client
 */
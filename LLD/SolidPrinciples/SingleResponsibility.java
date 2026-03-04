class CustomerService {
    public void serveCustomer(){
        System.out.println("Serving Customers...");
    }
}

class SupplyOrder {
    public void orderSupplies(){
        System.out.println("Ordering Supplies...");
    }
}

class InventoryManager {
    public void manageInventory(){
        System.out.println("Managing Inventory...");
    }
}

class BakeryCleaner {
    public void cleanBakery(){
        System.out.println("Cleaning Bakery...");
    }
}

public class SingleResponsibility {
    public static void main(String[] args) {
        InventoryManager inventoryManager = new InventoryManager();
        SupplyOrder supplyOrder = new SupplyOrder();
        CustomerService customerService = new CustomerService();
        BakeryCleaner cleaner = new BakeryCleaner();

        // Each class focuses on its specific responsibility
        inventoryManager.manageInventory();
        supplyOrder.orderSupplies();
        customerService.serveCustomer();
        cleaner.cleanBakery();
    }
}

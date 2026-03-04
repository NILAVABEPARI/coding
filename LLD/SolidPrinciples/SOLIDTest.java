class CustomerService2 {
    public void serveCustomers() {
        System.out.println("Serve customers");
    }
}

class InventoryManagement {
    public void manageInventory() {
        System.out.println("managing inventory");
    }
}

public class SOLIDTest {
    public static void main(String[] args) {
        InventoryManagement manager = new InventoryManagement();
        CustomerService2 customerService = new CustomerService2();

        manager.manageInventory();
        customerService.serveCustomers();
    }
}

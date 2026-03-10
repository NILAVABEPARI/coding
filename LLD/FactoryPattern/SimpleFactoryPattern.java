// Logistic Interface
interface Logistics {
    void send();
}

// Class implementing the Logistics Interface
class Road implements Logistics {
    @Override
    public void send() {
        System.out.println("Sending via Road");
    }
}

// Class implementing the Logistics Interface
class Air implements Logistics {
    @Override
    public void send() {
        System.out.println("Sending via Air");
    }
}

// Class implementing the Logistics Interface
class Sea implements Logistics {
    @Override
    public void send() {
        System.out.println("Sending via Sea");
    }
}

// Factory Class taking care of Logistics Object Creation
class LogisticsFactory {
    public static Logistics getLogisticsInstance(String type) {
        if (type.equalsIgnoreCase("Road")) {
            return new Road();
        } else if (type.equalsIgnoreCase("Air")) {
            return new Air();
        } else if (type.equalsIgnoreCase("Sea")) {
            return new Sea();
        }
        throw new IllegalArgumentException("Invalid logistics type: " + type);
    }
}

// Service Class using the Logistics Factory
class LogisticsService {
    public void send(String type) {
        Logistics logistics = LogisticsFactory.getLogisticsInstance(type);
        logistics.send();
    }
}

// Driver Class
public class SimpleFactoryPattern {
    public static void main(String[] args) {
        LogisticsService logisticsService = new LogisticsService();
        logisticsService.send("Road");
        logisticsService.send("Air");
        logisticsService.send("Sea");
    }
}
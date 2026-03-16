package StrategyPattern;

// strategy interface
interface MatchingStrategy {
    void match(String riderLocation);
}

// concrete strategy: nearest driver
class NearestDriverStrategy implements MatchingStrategy {
    @Override
    public void match(String riderLocation) {
        System.out.println("matching with nearest available driver to " + riderLocation);
        // Distance-based matching logic
    }
}

// concrete strategy: airport queue
class AirportQueueStrategy implements MatchingStrategy {
    @Override
    public void match(String riderLocation) {
        System.out.println("matching with FIFO airport queue for " + riderLocation);
        // Match first-in-line driver for airport pickup
    }
}

// concrete strategy: Surge Priority
class SurgePriorityStrategy implements MatchingStrategy {
    @Override
    public void match(String riderLocation) {
        System.out.println("matching rider using Surge Priority strategy near " + riderLocation);
        // Prioritize high-surge zones or premium drivers
    }
}

// context class: ride matching service
class RideMatchingService {
    private MatchingStrategy matchingStrategy;

    // Constructor injection of strategy
    public RideMatchingService(MatchingStrategy matchingStrategy) {
        this.matchingStrategy = matchingStrategy;
    }

    // Setter injection for changing strategy dynamically
    public void setStrategy(MatchingStrategy matchingStrategy) {
        this.matchingStrategy = matchingStrategy;
    }

    // Delegates the matching logic to the strategy
    public void matchRider(String location) {
        matchingStrategy.match(location);
    }
}

public class StrategyPattern {
    public static void main(String[] args) {
        RideMatchingService rideMatchingService = new RideMatchingService(new AirportQueueStrategy());
        rideMatchingService.matchRider("Terminal 1");

        // Using nearest driver strategy and later switching to surge priority
        RideMatchingService rideMatchingService2 = new RideMatchingService(new NearestDriverStrategy());
        rideMatchingService2.matchRider("Downtown");
        rideMatchingService2.setStrategy(new SurgePriorityStrategy());
        rideMatchingService2.matchRider("Downtown");
    }
}

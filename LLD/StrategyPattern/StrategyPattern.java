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
    }
}

// concrete strategy: airport
class AirportQueueStrategy implements MatchingStrategy {
    @Override
    public void match(String riderLocation) {
        System.out.println("matching with FIFO airport queue for " + riderLocation);
    }
}

// concrete strategy: Surge Priority
class SurgePriorityStrategy implements MatchingStrategy {
    @Override
    public void match(String riderLocation) {
        System.out.println("matching rider using Surge Priority strategy near " + riderLocation);
    }
}

// context class: ride matching service
class RideMatchingService {
    private MatchingStrategy matchingStrategy;

    public RideMatchingService(MatchingStrategy matchingStrategy) {
        this.matchingStrategy = matchingStrategy;
    }

    public void setStrategy(MatchingStrategy matchingStrategy) {
        this.matchingStrategy = matchingStrategy;
    }

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

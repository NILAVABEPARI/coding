interface Notification {
    public void send(String message);
}

/*
 * When a class implements an interface, it must provide implementations for all
 * methods declared in the interface.
 * 
 * extends is used when one class inherits another class.
 */

class EmailNotification implements Notification {
    @Override
    public void send(String message) {
        System.out.println("Sending email: " + message);
    }
}

class SMSNotification implements Notification {
    @Override
    public void send(String message) {
        System.out.println("Sending SMS: " + message);
    }
}

class PushNotification implements Notification {
    @Override
    public void send(String message) {
        System.out.println("Sending push notification: " + message);
    }
}

class SlackNotification implements Notification {
    @Override
    public void send(String message) {
        System.out.println("Sending Slack message: " + message);
    }
}

// ! An abstract class is a class that cannot be instantiated directly.
abstract class NotificationCreator {
    /*
     * Factory Method - subclasses decide what to create
     * abstract method: Has no implementation and must be implemented by subclasses
     */
    public abstract Notification createNotification();

    // Shared logic that uses the factory method
    public void send(String message) {
        Notification notification = createNotification();
        notification.send(message);
    }
}

class EmailNotificationCreator extends NotificationCreator {
    @Override
    public Notification createNotification() {
        return new EmailNotification();
    }
}

class SMSNotificationCreator extends NotificationCreator {
    @Override
    public Notification createNotification() {
        return new SMSNotification();
    }
}

class PushNotificationCreator extends NotificationCreator {
    @Override
    public Notification createNotification() {
        return new PushNotification();
    }
}

class SlackNotificationCreator extends NotificationCreator {
    @Override
    public Notification createNotification() {
        return new SlackNotification();
    }
}

public class FactoryPattern {
    public static void main(String[] args) {
        NotificationCreator creator;

        // Send Email
        creator = new EmailNotificationCreator();
        creator.send("Welcome to our platform!");

        // Send SMS
        creator = new SMSNotificationCreator();
        creator.send("Your OTP is 123456");

        // Send Push Notification
        creator = new PushNotificationCreator();
        creator.send("You have a new follower!");

        // Send Slack Message
        creator = new SlackNotificationCreator();
        creator.send("Standup in 10 minutes!");
    }
}

/*
 * Client (main)
 * |
 * | new EmailNotificationCreator()
 * v
 * EmailNotificationCreator Object
 * |
 * | creator.send("Welcome")
 * v
 * NotificationCreator.send()
 * |
 * | createNotification()
 * v
 * EmailNotificationCreator.createNotification()
 * |
 * | new EmailNotification()
 * v
 * EmailNotification Object
 * |
 * | send("Welcome")
 * v
 * Output: Sending email: Welcome to our platform!
 */
// ///////////////////////////////////
/*
 * Product Interface
 * ↓
 * Concrete Products
 * ↓
 * Abstract Creator
 * ↓
 * Concrete Creators
 */
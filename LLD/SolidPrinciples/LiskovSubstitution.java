// Notification class
class Notification {
    // method implementing send notification functionality
    public void sendNotification() {
        System.out.println("Notification sent");
    }
}

// Subclass of Notification class for Email Notification
class EmailNotification extends Notification {
    @Override
    public void sendNotification() {
        System.out.println("Email Notification sent");
    }
}

// Subclass of Notification class for Text Notification
class TextNotification extends Notification {
    @Override
    public void sendNotification() {
        System.out.println("Text Notification sent");
    }
}

// Main class
class LiskovSubstitution {
    // main method
    public static void main(String args[]) {
        /*
         * Replaced the Notification class object
         * with one of its subclass' objects
         */
        Notification notificationEmail = new EmailNotification();
        Notification notificationText = new TextNotification();

        // Working code on the notification object
        notificationEmail.sendNotification();
        notificationText.sendNotification();
    }
}

package TemplateMethod;

abstract class NotificationSender {

    public final void send(String to, String rawMessage) {
        // common logic
        rateLimitChecker(to);
        validateRecipient(to);
        String formatted = formatMessage(rawMessage);
        preSendAuditLog(to, formatted);

        // specific logic: defined by subclasses
        String composedMessage = composeMessage(formatted);
        sendMessage(to, composedMessage);

        // optional hook
        postSendAnalytics(to);
    }

    private void rateLimitChecker(String to) {
        System.out.println("Checking rate limits for : " + to);
    }

    private void validateRecipient(String to) {
        System.out.println("Validate Recipient : " + to);
    }

    private String formatMessage(String message) {
        return message.trim();
    }

    private void preSendAuditLog(String to, String formatted) {
        System.out.println("Logging before send: " + formatted + " to " + to);
    }

    protected abstract String composeMessage(String formattedMessage);

    protected abstract void sendMessage(String to, String message);

    protected void postSendAnalytics(String to) {
        System.out.println("Analytics updated for: " + to);
    }
}

class EmailNotification extends NotificationSender {
    @Override
    protected String composeMessage(String formattedMessage) {
        return "<html><body><p>" + formattedMessage + "</p></body></html>";
    }

    @Override
    protected void sendMessage(String to, String message) {
        System.out.println("Sending EMAIL to " + to + " with content: \n" + message);
    }
}

class SMSNotification extends NotificationSender {
    @Override
    protected String composeMessage(String formattedMessage) {
        return "[SMS] " + formattedMessage;
    }

    @Override
    protected void sendMessage(String to, String message) {
        System.out.println("Sending SMS to " + to + " with message: " + message);
    }

    @Override
    protected void postSendAnalytics(String to) {
        System.out.println("Custom SMS analytics for: " + to);
    }
}

public class TemplateMethod {
    public static void main(String[] args) {
        NotificationSender emailSender = new EmailNotification();
        emailSender.send("john@example.com", "Welcome to TUF+!");

        System.out.println(" ");

        NotificationSender smsSender = new SMSNotification();
        smsSender.send("9876543210", "Your OTP is 4567.");
    }
}

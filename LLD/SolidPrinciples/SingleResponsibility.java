class UserAuthenticator {
    public void authenticate(String username, String password) {
        System.out.println("Authenticating user..." + username);
    }
}

class UserRepository {
    public void saveUser(String user) {
        System.out.println("Saving user: " + user + " to database...");
    }
}

class EmailService {
    public void sendEmail(String email) {
        System.out.println("Sending email to: " + email);
    }
}

class UserLogger {
    public void log(String message) {
        System.out.println("Logging user activity..." + message);
    }
}

public class SingleResponsibility {
    public static void main(String[] args) {
        UserAuthenticator auth = new UserAuthenticator();
        UserRepository repo = new UserRepository();
        EmailService emailService = new EmailService();
        UserLogger logger = new UserLogger();

        auth.authenticate("admin", "password");
        repo.saveUser("admin");
        emailService.sendEmail("admin@example.com");
        logger.log("User registered");
    }
}
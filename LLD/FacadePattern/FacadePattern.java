class PaymentService {
    public void makePayment(String accountID, double amount) {
        System.out.println("Payment of " + amount + " successful for account " + accountID);
    }
}

class SeatReservationService {
    public void reserveSeat(String movieID, String seatNumber) {
        System.out.println("Seat " + seatNumber + " reserved for movie " + movieID);
    }
}

class NotificationService {
    public void sendNotification(String userEmail) {
        System.out.println("Booking confirmation sent to " + userEmail);
    }
}

class TicketService {
    public void generateTicket(String movieID, String seatNumber) {
        System.out.println("Ticket generated for movie " + movieID + " Seat: " + seatNumber);
    }
}

class MovieBookingFacade {
    private PaymentService paymentService;
    private SeatReservationService seatReservationService;
    private NotificationService notificationService;
    private TicketService ticketService;

    public MovieBookingFacade() {
        this.paymentService = new PaymentService();
        this.seatReservationService = new SeatReservationService();
        this.notificationService = new NotificationService();
        this.ticketService = new TicketService();
    }

    public void bookMovieTicket(String accountID, String movieID, String seatNumber, String userEmail, double amount) {
        paymentService.makePayment(accountID, amount);
        seatReservationService.reserveSeat(movieID, seatNumber);
        notificationService.sendNotification(userEmail);
        ticketService.generateTicket(movieID, seatNumber);

        System.out.println("Movie ticket booking completed successfully!!!");
    }
}

public class FacadePattern {
    public static void main(String[] args) {
        MovieBookingFacade movieBookingFacade = new MovieBookingFacade();
        movieBookingFacade.bookMovieTicket("user123", "movie123", "A10", "nilavastnd@gmail.com", 500);
    }
}

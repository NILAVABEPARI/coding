interface PaymentProcessor {
    void processPayment(double amount);
}

class CreditCardPaymentProcessor implements PaymentProcessor {
    @Override
    public void processPayment(double amount) {
        System.out.println("Processing credit card payment of $" + amount);
    }
}

class PayPalPaymentProcessor implements PaymentProcessor {
    @Override
    public void processPayment(double amount) {
        System.out.println("Processing PayPal payment of $" + amount);
    }
}

class CheckoutService {
    public void checkoutService(PaymentProcessor processor, double amount) {
        processor.processPayment(amount);
    }
}

public class OpenClosePrinciple {
    public static void main(String[] args) {
        PaymentProcessor credit = new CreditCardPaymentProcessor();
        PaymentProcessor paypal = new PayPalPaymentProcessor();

        CheckoutService checkout = new CheckoutService();
        checkout.checkoutService(credit, 100);
        checkout.checkoutService(paypal, 150);
    }
}

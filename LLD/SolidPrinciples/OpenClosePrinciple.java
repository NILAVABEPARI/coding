interface PaymentProcessor{
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

public class OpenClosePrinciple {
    public static void main(String[] args) {
        PaymentProcessor credit = new CreditCardPaymentProcessor();
        PaymentProcessor paypal = new PayPalPaymentProcessor();

        processPayment(credit, 100);
        processPayment(paypal, 150);
    }

    public static void processPayment(PaymentProcessor processor, double amount) {
        processor.processPayment(amount);
    }
}

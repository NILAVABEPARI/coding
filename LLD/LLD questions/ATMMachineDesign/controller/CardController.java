package controller;

import domain.ATM;
import domain.exception.InvalidATMOperationException;
import service.ATMService;

public class CardController {
    private final ATMService atmService;

    public CardController(ATMService atmService) {
        this.atmService = atmService;
    }

    public boolean insertCard(String atmId, String cardId) {
        ATM atm = atmService.getATM(atmId);
        // Validation check
        if (atm == null)
            return false;
        try {
            atm.insertCard(cardId);
            return true; // state orchestrates services
        } catch (InvalidATMOperationException ex) {
            System.out.println("[ERROR] " + ex.getMessage());
            return false;
        }
    }

    public void ejectCard(String atmId) {
        ATM atm = atmService.getATM(atmId);
        if (atm == null)
            return;
        try {
            atm.ejectCard();
        } catch (InvalidATMOperationException ex) {
            System.out.println("[ERROR] " + ex.getMessage());
        }
    }

    public boolean authenticateCard(String atmId, String cardId, String pin) {
        ATM atm = atmService.getATM(atmId);
        if (atm == null)
            return false;
        try {
            atm.enterPin(pin);
            return true;
        } catch (InvalidATMOperationException ex) {
            System.out.println("[ERROR] " + ex.getMessage());
            return false;
        }
    }
}
package domain;

public class InternalDispatcher {

    private static final InternalDispatcher INSTANCE = new InternalDispatcher();

    private InternalDispatcher() {
    }

    public static InternalDispatcher getInstance() {
        return INSTANCE;
    }

    // elevatorController is known based on button press origin
    public void submitInternalRequest(int destinationFloor, ElevatorController controller) {
        controller.submitRequest(destinationFloor);
    }
}
package other;

import java.util.ArrayList;
import java.util.List;

public class Building2 {
    List<Floor> floors = new ArrayList<>();

    public Building2(int totalFloors, ExternalDispatcher dispatcher) {
        for (int i = 1; i <= totalFloors; i++) {
            floors.add(new Floor(i, dispatcher));
        }
    }

    public Floor getFloor(int floor) {
        return floors.get(floor - 1);
    }
}

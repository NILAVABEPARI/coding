package main;

import java.util.Arrays;

import other.Building2;
import other.ElevatorCar;
import other.ElevatorController;
import other.ElevatorScheduler;
import other.ExternalDispatcher;
import other.InternalButton;
import other.NearestElevatorStrategy;

public class Demo {

    public static void main(String[] args) {

        try {

            // 1. Create elevator cars and their controllers
            ElevatorCar car1 = new ElevatorCar(1);
            ElevatorController controller1 = new ElevatorController(car1);

            ElevatorCar car2 = new ElevatorCar(2);
            ElevatorController controller2 = new ElevatorController(car2);

            // 2. Create one internal buttons for each elevator
            InternalButton internalButton_for_elevator1 = new InternalButton(controller1);
            InternalButton internalButton_for_elevator2 = new InternalButton(controller2);

            // 3. create Scheduler with Nearest Strategy
            ElevatorScheduler elevatorScheduler = new ElevatorScheduler(
                    Arrays.asList(controller1, controller2),
                    new NearestElevatorStrategy());

            // 4. Create External Dispatcher
            ExternalDispatcher externalDispatcher = new ExternalDispatcher(elevatorScheduler);

            // Create a 5 floor building:
            Building2 building = new Building2(5, externalDispatcher);

            // 6. Start both the elevator controllers threads
            new Thread(controller1, "Elevator-1").start();
            new Thread(controller2, "Elevator-2").start();

            // Lets submit the requests
            /*
             * 1. External Call : Floor 3 UP
             * 2. External Call : Floor 5 DOWN
             * 3. Internal Call : Elevator 1 (press 4)
             * 4. Internal Call : Elevator 1 (press 5)
             * 5. External Call : Floor 1 DOWN
             * 6. External Call : Floor 2 UP
             * 7. Internal Call : Elevator 2 (press 4)
             */

            building.getFloor(3).pressUpButton();
            Thread.sleep(5);

            building.getFloor(5).pressDownButton();
            Thread.sleep(5);

            internalButton_for_elevator1.pressButton(4); // user inside elevator 1 presses floor 4
            Thread.sleep(5);

            internalButton_for_elevator1.pressButton(5); // user inside elevator 1 presses floor 5
            Thread.sleep(5);

            building.getFloor(1).pressDownButton();
            Thread.sleep(5);

            building.getFloor(2).pressUpButton();
            Thread.sleep(5);

            internalButton_for_elevator1.pressButton(2); // user inside elevator1 presses floor 2
            Thread.sleep(5);

            internalButton_for_elevator2.pressButton(4); // user inside elevator2 presses floor 4

        } catch (InterruptedException e) {

        }

    }
}

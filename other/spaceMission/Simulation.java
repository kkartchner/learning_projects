package spaceMission;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.io.File;
import java.util.Scanner;

public class Simulation {
    public ArrayList<Item> loadItems(String filePath) throws FileNotFoundException {
        System.out.println("Loading items from \"" + filePath + "\"...");

        File file = new File(filePath);
        Scanner input = new Scanner(file);

        ArrayList<Item> items = new ArrayList<>();
        while (input.hasNextLine()) {
            String[] itemData = input.nextLine().split("=");
            items.add(new Item(itemData[0], Integer.parseInt(itemData[1])));
        }

        return items;
    }

    public ArrayList<Rocket> loadU1Rockets(final ArrayList<Item> cargoToLoad){
        System.out.println("Adding items to U1 rockets...");

        ArrayList<Rocket> u1Rockets = new ArrayList<>();
        ArrayList<Item> remainingCargo = new ArrayList<>(cargoToLoad);

        while (!remainingCargo.isEmpty()){
            U1 rocket = new U1();
            ArrayList<Item> loadedCargo = new ArrayList<>();

            for (Item item : remainingCargo){
                if (rocket.canCarry(item)){
                    rocket.carry(item);
                    loadedCargo.add(item);
                }
            }

            u1Rockets.add(rocket);
            remainingCargo.removeAll(loadedCargo);
        }

        return u1Rockets;
    }

    public ArrayList<Rocket> loadU2Rockets(final ArrayList<Item> cargoToLoad){
        System.out.println("Adding items to U2 rockets...");

        ArrayList<Rocket> u2Rockets = new ArrayList<>();
        ArrayList<Item> remainingCargo = new ArrayList<>(cargoToLoad);

        while (!remainingCargo.isEmpty()){
            U2 rocket = new U2();
            ArrayList<Item> loadedCargo = new ArrayList<>();

            for (Item item : remainingCargo){
                if (rocket.canCarry(item)){
                    rocket.carry(item);
                    loadedCargo.add(item);
                }
            }

            u2Rockets.add(rocket);
            remainingCargo.removeAll(loadedCargo);
        }

        return u2Rockets;
    }

    public int runSimulation(ArrayList<Rocket> rockets){
        System.out.println("\nRunning " + rockets.get(0).getClass().getSimpleName() + " rocket simulation...");

        int totalBudget = 0;
        boolean launchSucceeded = false;
        boolean landSucceeded = false;

        for (Rocket rocket : rockets){
            do {
                totalBudget += rocket.cost;
                launchSucceeded = rocket.launch();
                landSucceeded = rocket.land();
            } while (!launchSucceeded || !landSucceeded);
        }

        return totalBudget;
    }
}

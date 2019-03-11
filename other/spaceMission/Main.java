package spaceMission;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Simulation simulation = new Simulation();

        ArrayList<Item> phaseOneItems = new ArrayList<>();
        ArrayList<Item> phaseTwoItems = new ArrayList<>();

        try {
            phaseOneItems = simulation.loadItems("data/phase-1.txt");
            phaseTwoItems = simulation.loadItems("data/phase-2.txt");
        } catch (Exception e){
            System.out.println(e);
        }

        ArrayList<Rocket> u1Rockets = simulation.loadU1Rockets(phaseOneItems);
        u1Rockets.addAll(simulation.loadU1Rockets(phaseTwoItems));

        double u1BudgetInBillions = simulation.runSimulation(u1Rockets) / 1000.0;
        System.out.println("Total cost of U1 rockets is $" + String.format("%.2f", u1BudgetInBillions) + " Billion\n");

        ArrayList<Rocket> u2Rockets = simulation.loadU2Rockets(phaseOneItems);
        u2Rockets.addAll(simulation.loadU2Rockets(phaseTwoItems));

        double u2BudgetInBillions = simulation.runSimulation(u2Rockets) / 1000.0;
        System.out.println("Total cost of U2 rockets is $" + String.format("%.2f", u2BudgetInBillions) + " Billion");
    }
}

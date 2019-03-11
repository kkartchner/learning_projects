package spaceMission;

public class U1 extends Rocket{
    public U1(){
        super.cost = 100;                 // Million
        super.cargoWeight = 0;
        super.maxCargoWeight = 8_000;     // Weight in kg
    }

    @Override
    public boolean launch() {
        double explosionChance = .05 * ((double) cargoWeight / maxCargoWeight);
        return Math.random() > explosionChance;
    }

    @Override
    public boolean land() {
        double explosionChance = .01 * ((double) cargoWeight / maxCargoWeight);
        return Math.random() > explosionChance;
    }
}

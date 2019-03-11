package spaceMission;

public class U2 extends Rocket{
    public U2(){
        super.cost = 120;           // Million
        super.cargoWeight = 0;
        super.maxCargoWeight = 11_000;     // Weight in kg
    }

    @Override
    public boolean launch() {
        double explosionChance = .04 * ((double) cargoWeight / maxCargoWeight);
        return Math.random() > explosionChance;
    }

    @Override
    public boolean land() {
        double explosionChance = .08 * ((double) cargoWeight / maxCargoWeight);
        return Math.random() > explosionChance;
    }
}

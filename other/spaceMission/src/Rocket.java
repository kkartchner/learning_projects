package spaceMission;

public class Rocket implements SpaceShip {
    public int cargoWeight;
    public int maxCargoWeight;
    public int cost;

    public boolean launch() {
        return true;
    }

    public boolean land() {
        return true;
    }

    public boolean canCarry(Item item) {
        return item.weight + cargoWeight <= maxCargoWeight;
    }

    public void carry(Item item) {
        cargoWeight += item.weight;
    }

}

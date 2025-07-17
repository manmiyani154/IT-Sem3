class Player {
    String name = "Player";
}

class CricketPlayer extends Player {
    String team = "Cricket Team";
}

class Batsman extends CricketPlayer {
    void show() {
        System.out.println(name + " - " + team + " - Batsman");
    }
}

class Bowler extends CricketPlayer {
    void show() {
        System.out.println(name + " - " + team + " - Bowler");
    }
}

public class Prog11 {
    public static void main(String[] args) {
        Batsman b = new Batsman();
        Bowler w = new Bowler();
        b.show();
        w.show();
    }
}

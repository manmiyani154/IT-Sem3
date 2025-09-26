class Player {
    String name;
    int age;

    Player(String name, int age) {
        this.name = name;
        this.age = age;
    }

    void show() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}

class CricketPlayer extends Player {
    String team;

    CricketPlayer(String name, int age, String team) {
        super(name, age);
        this.team = team;
    }

    void show() {
        super.show();
        System.out.println("Team: " + team);
    }
}

class Batsman extends CricketPlayer {
    int runs;

    Batsman(String name, int age, String team, int runs) {
        super(name, age, team);
        this.runs = runs;
    }

    void show() {
        super.show();
        System.out.println("Runs: " + runs);
    }
}

class Bowler extends CricketPlayer {
    int wickets;

    Bowler(String name, int age, String team, int wickets) {
        super(name, age, team);
        this.wickets = wickets;
    }

    void show() {
        super.show();
        System.out.println("Wickets: " + wickets);
    }
}

class Prog11 {
public static void main(String[] args) {
Batsman b = new Batsman("Virat", 34, "India", 12000);
Bowler bw = new Bowler("Bumrah", 30, "India", 250);


System.out.println("\nBatsman Details:");
b.show();
System.out.println("\nBowler Details:");
bw.show();
}

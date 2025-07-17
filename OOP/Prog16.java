public class Prog16 {
    public static void main(String[] args) {
        try {
            int total = 0;
            for (int i = 0; i < 5; i++) {
                int mark = Integer.parseInt(args[i]);
                if (mark < 0 || mark > 100)
                    throw new Exception("Invalid marks");
                total += mark;
            }
            System.out.println("Average: " + (total / 5.0));
        } catch (NumberFormatException e) {
            System.out.println("Marks must be integers.");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}


import CE_Dept.Machine_Detail_CE;
import IT_Dept.Machine_Detail_IT;

public class Prog15 {
    public static void main(String[] args) {
        Machine_Detail_CE ce = new Machine_Detail_CE();
        Machine_Detail_IT it = new Machine_Detail_IT();
        ce.display();
        it.display();
    }
}

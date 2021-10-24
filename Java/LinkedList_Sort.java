import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

public class Java8Demo {

    public static void main(String args[]) {

        List<String> listOfWeightLossFood = new LinkedList<>(Arrays.asList("beans", "oats", "avocados", "broccoli"));

        System.out.println("before sorting: " + listOfWeightLossFood);
        listOfWeightLossFood.sort(Comparator.reverseOrder());
        System.out.println("after sorting: " + listOfWeightLossFood);

    }

}

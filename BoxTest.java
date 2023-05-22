import java.util.ArrayList;
import java.util.List;
public class BoxTest {
   public static void main(String[] args) {
      List<Integer> list = new ArrayList<>();
      list.add(new Integer(1));
      list.add(new Integer(2));
      list.add(new Integer(3));
//       list.add(1);
//       list.add(2);
//       list.add(3);
      System.out.println(list.toString());
      for (int x : list) {
         System.out.println(x);
      }
   }
}
public class StringTest {
   public static void main(String[] args) {
      String s1 = "abc1";
      String s2 = "abc1";
      System.out.println(s1);
      System.out.println(s2);
      System.out.println(s1 == s2); // true
      int x = 1;
      String s3 = "abc" + x;
      System.out.println(s1);
      System.out.println(s3);
      System.out.println(s1 == s3); // false
      s3 = s3.intern();
      System.out.println(s1);
      System.out.println(s3);
      System.out.println(s1 == s3); // true
//         StringBuilder sb = new StringBuilder();
//         sb.append("abc");
//         sb.append(666);
//         String s = sb.toString();
//         System.out.println(s);
    }
}
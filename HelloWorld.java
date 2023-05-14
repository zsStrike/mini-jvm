public class HelloWorld {
   public static void main(String[] args) {
      System.out.println("中文测试，检测中文转换");
      System.out.println("Hello, world! Prepared to print args， argLen is");
      System.out.println(args.length);
      for (String arg : args) {
          System.out.println(arg);
      }
   }
}
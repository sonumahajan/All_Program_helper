interface GrandParent {
   int grand_age = 84;
   public void grand_show();
}
interface Parent1 extends GrandParent {
   int parent1_age = 52;
   public void parent1_show();
}
interface Parent2 extends GrandParent {
   int parent2_age = 45;
   public void parent2_show();
}
class GrandChild implements Parent1,Parent2 {
   GrandChild(int age)
   {
      System.out.println("Age of GrandChild is = " + age);
   }
   public void grand_show()
   {
      System.out.println("Age of GrandParent is = " + grand_age);
   }
   public void parent1_show()
   {
      System.out.println("Age of 1st Parent is = " + parent1_age);
   }
   public void parent2_show()
   {
      System.out.println("Age of 2nd Parent is = " + parent2_age);
   }
}
class HybridInheritance {
   public static void main(String args[]) {
      GrandChild obj = new GrandChild(15);
      obj.grand_show();
      obj.parent1_show();
      obj.parent2_show();
   }
}
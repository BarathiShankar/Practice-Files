//Program to create multiple inheritence using interfaces
interface walks
{
    void walk();
}
interface swims
{
    void swim();
}
class turtle implements walks,swims{
    @Override
    public void swim()
    {
        System.out.println("I can swim in water");
    }
    @Override
    public void walk()
    {
        System.out.println("I can walk on land");
    }
}
public class multi_inherit {
    public static void main(String[] args)
    {
        turtle t= new turtle();
        t.walk();
        t.swim();
        System.out.println("\n\nR.BARATHI SHANKAR - 2024503063");
    }
//COMPLETED
}

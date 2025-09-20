//Program to use exceptions in maths calculator
class MathCalculator
{
    static double calculatePower(double base,double exponent)
    {
        double ans=0;
        try
        {
            if(base==0 && exponent<0)
                throw new IllegalArgumentException("Illegal arguement Error");
            if(base<0 && exponent<0)
                throw new ArithmeticException("Arithemetic Error");
            if(base==0 && exponent==0)
                throw new UnsupportedOperationException("Invalid operation Error");
            ans = Math.pow(base,exponent);
        }
        catch(IllegalArgumentException e)
        {
            System.out.println(e.getMessage());
        }
        catch(ArithmeticException e)
        {
            System.out.println(e.getMessage());
        }
        catch(UnsupportedOperationException e)
        {
            System.out.println(e.getMessage());
        }
        return ans;
    }
    static int factorial(int n)
    {
        int fact=0;
        try
        {
            if(n<0)
                throw new IllegalArgumentException("Illegal ArgumentError");
            if(n>20)
                throw new ArithmeticException("Arithmetic Error");
            for(int i=1;i<=n;i++)
            {
                fact*=i;
            }
        }
        catch(IllegalArgumentException e){
            System.out.println(e.getMessage());
        }
        catch(ArithmeticException e)
        {
            System.out.println(e.getMessage());
        }
        return fact;
    }
    static double safeDivide(double dividend,double divisor)
    {
        double div=0;
        try
        {
            if(divisor==0)
                throw new ArithmeticException("Arithmetic Error");
            if(divisor==0 && dividend==0)
                throw new IllegalArgumentException("Illegal Argument Error");
            div=dividend/divisor;
        }
        catch(ArithmeticException e)
        {
            System.out.println(e.getMessage());
        }
        catch(IllegalArgumentException e)
        {
            System.out.println(e.getMessage());
        }
        return div;
    }
}
public class w8q1
{
    public static void main(String[] args)
    {
        double ans;//Provided static data for running
        int a;
        ans=MathCalculator.calculatePower(0,0);
        a=MathCalculator.factorial(-5);
        ans=MathCalculator.safeDivide(5,0);
    }
}

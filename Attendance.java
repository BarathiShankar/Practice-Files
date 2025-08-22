//Program to create a attendance array and simply print the attendance percentage 
import java.util.Scanner;
class Attendance
{
  static
  {
    System.out.println("-> This program uses 1 or 0 digits to mark attendance\n"
                       +"-> To print the total attendance in week and per day attendance\n");
  }
public static void main(String[] args)
{
int[][] attendance=new int[5][8];
String[] days={"Monday","Tuesday","Wednesday","Thursday","Friday"};
int[] dailyData={0,0,0,0,0};
int weeklyData=0;
Scanner sc=new Scanner(System.in);
System.out.println("Enter the attendance Details -");
System.out.println("1 for Present or 0 for absent : ");
for(int i=0;i<5;i++)
{
System.out.println(days[i]);
for(int j=0;j<8;j++)
{
do
{
System.out.print("HOUR - "+(j+1)+":");
attendance[i][j]=sc.nextInt();
if(attendance[i][j]!=1 && attendance[i][j]!=0)
System.out.println("Invalid Input");
else if(attendance[i][j]==1)
{
dailyData[i]++;
weeklyData++;
}
}while(attendance[i][j]!=1 && attendance[i][j]!=0);
}
System.out.println();
}
for(int i=0;i<5;i++)
{
System.out.println(days[i]+" = "+(dailyData[i]*100/8));
}
System.out.println("Weekly Attendance = "+(weeklyData*100/40));
}
}
//COMPLETED

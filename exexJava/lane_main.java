import java.util.*;

public class lane_main
{
    public static void main(String[] args)
    {
        int n,m;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        m = scan.nextInt();
        lane Stand = new lane(n,m);
        for(int i = 0 ;i < m ;i ++)
        {
            int x,y;
            x = scan.nextInt();
            y = scan.nextInt();
            if(x == 0)Stand.DepartCar(y - 1);
            else Stand.InsertCar(y);
        }
    }
}
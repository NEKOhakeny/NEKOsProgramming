import java.util.*;


public class Vector
{
    public static void main(String[] args)
    {
        int n;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        int m = scan.nextInt();
        Vector< Queue< Integer > > vec = new Vector< Queue<Integer> >(m);
        for(int i = 0;i < n ;i ++)
        {
            int x,y;
            x = scan.nextInt();
            y = scan.nextInt();
            vec[x].add(y);
        }
        for(int i = 0; i < n;i ++)
        {
            for(var g : vec[i])
            {
                System.out.print(g);
                System.out.print(" ");
            }
            System.out.println();
        }

    }


}
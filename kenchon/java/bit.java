import java.util.Scanner;

public class bit
{
    int sum = 0;
    int [] a;
    int k;
    bit(int k,int n)
    {
        a = new int[n];
        this.k = k;
    }
    boolean calc()
    {
        
        for(int bt = 0; bt < 1<<a.length ; bt++)
        {
            int sum = 0;
            for(int j = 0; j < 1<<a.length ; j++)
            {
                int m = bt & 1 << j;
                if(1 == m)sum += a[j];
            }
            if(sum == k)return true;
        }
        return false;

    }

}
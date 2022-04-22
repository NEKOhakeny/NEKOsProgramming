import java.util.*;


public class lane
{
    int n,m;
    int[][] Lane;
    int[] head,tail,num;

    public lane(int n,int m)
    {
        this.n = n;
        this.m = m;
        Lane = new int[n][m];
        head = new int[n];
        tail = new int[n];
        num = new int[n];
        for(int i = 0 ;i < n ; i ++)
        {
            head[i] = tail[i] = num[i] = 0;
        }
    }
    void InsertCar(int car)
    {
        int al = cmp_lane();
        int h = head[al];
        num[al]++;
        head[al] = (h + 1) % m;
        Lane[al][h] = car;
    }
    void DepartCar(int ln)
    {
        int tl = tail[ln];
        prifunc(Lane[ln][tl]);
        tail[ln] = (tl + 1) % m;
        num[ln] --;
    }

    
    int cmp_lane()
    {
        
        int min = Integer.MAX_VALUE;
        int mini = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(min <= num[i])continue;
            min = num[i];
            mini = i;
        }
        return mini;
    }
    void prifunc(int x)
    {
        System.out.println( x );
    }

}
import java.util.Scanner;
public class cp3_5
{
    public static int[] aray;
        public static void main(String[] args)
    {
        Scanner scaner = new Scanner(System.in);
        int n = scaner.nextInt();
        aray = new int[n];
        for(int i = 0; i < n ; i++)aray[i] = scaner.nextInt();
        int ans = calc(n);
        System.out.println(ans);
    }

    static int calc(int n)
    {
        int min = Integer.MAX_VALUE;
        for(var g : aray){
            int x = g;
            int cnt = 0;
            while(true){
                if(x % 2 != 0)break;
                x /= 2;
                cnt++;
            }
            if(cnt < min)min = cnt;
        }
        return min;
    }

}
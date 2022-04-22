import java.util.Scanner;


public class cp3_6
{
    public static void main(String[] args)
    {
        Scanner scaner = new Scanner(System.in);
        int k = scaner.nextInt();
        int n = scaner.nextInt();
        int ans = calc(n , k);
        System.out.println(ans);
    }
    static int calc(int n,int k)
    {
        int ans = (n + 2) * (n + 1) / 2 - (n - k + 1) * (n - k + 2) * 3 / 2;
        return ans;

    }


}
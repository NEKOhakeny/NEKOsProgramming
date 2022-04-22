import java.util.*;


class Type_inf<T extends > 
{
    T chmin(T a,T b)
    {
        if(a < b)a = b;
        return a;
    }
}

public class cp5_4
{
    
    int n;
    int k;
    cp5_4(int n,int k)
    {
        this.n = n;
        this.k = k;
    }
    
    
    Scanner scan = new Scanner(System.in);
    int w = scan.nextInt();
    int[] a = new int[n];
    int[][] dp = new int[n][w + 1];
    void definite()
    {
        for(int i = 0; i < n ; i++){
            a[i] = scan.nextInt();
            Arrays.fill(dp[i],0);
        }
    }
    Type_inf TF = new Type_inf();
    void dinamic()
    {
        dp[0][a[0]] = 1;
        
        for(int i = 1; i < n ; i++)
        {
            for(int j = 0; j < w + 1; j++)
            {
                dp[i][j] = dp[i - 1][j];
                int x = j - a[i];
                if(x < 0)continue;
                dp[i][j] = TF.chmin(dp[i][j],dp[i - 1][j - a[i]] + 1);
            }
        }
        
    }


}
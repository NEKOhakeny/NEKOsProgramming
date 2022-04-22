import java.util.Scanner;
public class cp3_3 {
    public static void main(String[] args){
        SecondMin();
        return;
    }
    public static void SecondMin(){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] aray = new int[n];
        for(int i = 0 ; i < n ; i++)aray[i] = scanner.nextInt();
        int min = Integer.MAX_VALUE;
        int max = Integer.MAX_VALUE;
        for(var g : aray){
            if(min > g){
                max = min;
                min = g; 
            }
            else if(max > g)max = g;
        }
        System.out.println(max);
    }   
}
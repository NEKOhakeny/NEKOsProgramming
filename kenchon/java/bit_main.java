import java.util.Scanner;

public class bit_main
{
    public static void main(String[] args)
    {
        Scanner scaner = new Scanner(System.in);
        int n = scaner.nextInt();
        int k = scaner.nextInt();

        bit Bit = new bit(k,n);
        if(Bit.calc())System.out.print("exist");
        else System.out.println("no");
    }

}


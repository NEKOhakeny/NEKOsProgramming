import java.util.*;

public class Sphere
{
    double radius;
    Sphere(double radius)
    {
        this.radius = radius;
    }
    double getHeightOfContactPoint(Sphere Sp2)
    {
        double r1 = Math.max(radius,Sp2.radius);
        double r2 = Math.min(radius,Sp2.radius);
        return r2 + (r1 - r2) * r2 /(r1 + r2);
    }

}
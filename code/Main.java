package code;
import code.Idata.*;

public class Main
{

    public static void main(String[] args)
    {
        if (unitTestIdata())
            System.out.println("unitTestIdata() succeeded");
        else
            System.out.println("unitTestIdata() failed");
    }

    public static boolean unitTestIdata()
    {
        ProductionIdata production = new ProductionIdata();
        if (production.getMainWork() != MainWork.Paper) return false; // Fail
        if (production.getDepartment() != "Production") return false; // Fail

        DevIdata dev = new DevIdata();
        if (dev.getMainWork() != MainWork.Digital) return false; // Fail
        if (dev.getDepartment() != "Development")  return false; // Fail
            
        return true; // Success
    }

}
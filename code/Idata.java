package code;
public class Idata
{

    public enum MainWork
    {
        Paper, Digital
    }

    public interface IIdata
    {
        public MainWork getMainWork();
        public String getDepartment();
    }

    public static abstract class BaseIdata implements IIdata
    {
        abstract public MainWork getMainWork();
        abstract public String getDepartment();
    }

    public static class ProductionIdata extends BaseIdata
    {
        public MainWork getMainWork()
        {
            return MainWork.Paper;
        }

        public String getDepartment()
        {
            return "Production";
        }
    }

    public static class DevIdata extends BaseIdata
    {
        public MainWork getMainWork()
        {
            return MainWork.Digital;
        }

        public String getDepartment()
        {
            return "Development";
        }
    }

}

import java.util.*;
import java.lang.*;


class square implements Runnable
{
    int y;
    public square(int x)
    {
        y=x;
    }
    public void run()
    {
        System.out.println("Square of the number: "+(y*y));
        //Use Threads to start a thread to find the cube of the given number y
        Thread t = new Thread (new cube(y));
        t.start();

    }
}

class cube implements Runnable //Something missing in the code here related to interfaces
{
    int y;
    //Use a constructor to assign the value of y
    public cube( int x){
        y=x;
    }
    public void run()
    {
        System.out.println("Cube of the number: "+(y*y*y));
    }
}

class generate implements Runnable
{
    public void run()
    {
        int num=0;
        Random r = new Random();
            num= r.nextInt(100);
                System.out.println("Number generated: "+num);
                Thread t1= new Thread(new square(num));
                t1.start();
    }
}

public class ThreadsGenerate
{
    public static void main(String args[])
    {
        
        try{
            for(int i=0;i<5;i++)
            {
                //Generate a number using Threads and start the given thread
                Thread obj = new Thread(new generate());
                obj.start();
                Thread.sleep(1000); //Find the error in this given line -- sleep should be prefixed by thread
            }
        }
         catch(Exception e)
        {
            System.out.println(e);
        }
    }
}


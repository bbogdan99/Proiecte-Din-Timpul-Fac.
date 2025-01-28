package work;

public class FpsTimer
{
    private double timePerUpdate, delta;
    private long now, lastTime;

    public FpsTimer(int fps)
    {
        timePerUpdate=1000000000/fps;
        delta=0;
        lastTime=System.nanoTime();
    }

    public boolean check()
    {
        now=System.nanoTime();
        delta=(now-lastTime)/timePerUpdate;

        if(delta>=1)
        {
            lastTime=now;
            return true;
        }
        else return false;
    }
}

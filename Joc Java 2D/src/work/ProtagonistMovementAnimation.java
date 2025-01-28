package work;

import java.awt.image.BufferedImage;
import java.util.Random;

public class ProtagonistMovementAnimation
{
    private int speed, index=1;
    private long lastTime, timer=0;
    private BufferedImage Frame1, Frame2;

    public ProtagonistMovementAnimation (int speed, BufferedImage Frame1, BufferedImage Frame2)
    {
        this.speed=speed;
        this.Frame1=Frame1;
        this.Frame2=Frame2;
        timer=0;
        index=1;
        lastTime = System.currentTimeMillis();
    }

    public void tick()
    {
        timer+= System.currentTimeMillis()-lastTime;
        lastTime=System.currentTimeMillis();

        if (timer>speed)
        {
            index++;
            timer=0;
            if (index>2)
                index=1;
        }
    }

    public BufferedImage getCurrentFrame()
    {
        tick();
        //System.out.println(index);
        if (index==2)
            return Frame2;
        return Frame1;
    }
}

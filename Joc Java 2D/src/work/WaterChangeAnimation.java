package work;

import java.awt.image.BufferedImage;
import java.util.Random;

public class WaterChangeAnimation
{
    private int speed, index=1;
    private long lastTime, timer=0;
    private BufferedImage waterFrame1, waterFrame2, waterFrame3, waterFrame4;

    public WaterChangeAnimation (int speed, BufferedImage waterFrame1, BufferedImage waterFrame2,
                                 BufferedImage waterFrame3, BufferedImage waterFrame4)
    {
        this.speed=speed;
        this.waterFrame1=waterFrame1;
        this.waterFrame2=waterFrame2;
        this.waterFrame3=waterFrame3;
        this.waterFrame4=waterFrame4;
        timer=0;
        index=2;
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
            if (index>4)
                index=1;
        }
    }

    /*public void tick()
    {
        timer+= System.currentTimeMillis()-lastTime;
        lastTime=System.currentTimeMillis();

        if (timer>speed)
        {
            Random rand = new Random();
            index = rand.nextInt(3)+1;
            timer=0;
        }
    }*/

    public BufferedImage getCurrentFrame()
    {
        tick();
        //System.out.println(index);
        if (index==2)
            return waterFrame2;
        if (index==3)
            return waterFrame3;
        if (index==4)
            return waterFrame4;
        return waterFrame1;
    }
}

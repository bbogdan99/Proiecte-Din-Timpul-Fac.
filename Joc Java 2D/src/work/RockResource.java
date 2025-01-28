package work;

import java.awt.*;

public class RockResource extends StaticEntity
{

    private int rockResourceState;

    public RockResource(Handler handler, float x, float y, int width, int height) {
        super(handler, x, y, width, height);
        health=0;
        rockResourceState=1;
    }

    @Override
    public void tick()
    {
        if (rockResourceState==1)
        {
            float x1,x2, y1,y2;
            x1=x-handler.getGameCamera().getxOffset()+width;
            y1=x-handler.getGameCamera().getyOffset()+height;
            y2=handler.getGame().getHeight()/2;
            x2=handler.getGame().getWidth()/2;
            float xFin =(x2-x1)*(x2-x1); float yFin= (y2-y1)*(y2-y1);
            int test = (int)(Math.sqrt(xFin + yFin));
            //System.out.println(test);
            if (handler.getKeyManager().act && test<70)
            {
                handler.getWorld().getEntityManager().getProtagonist().rockResourceInc();
                rockResourceState=-1;
            }

        }
    }

    @Override
    public void render(Graphics g)
    {
        if (rockResourceState==1)
            g.drawImage(Assets.logResource,(int) (x - handler.getGameCamera().getxOffset()),
                    (int) (y - handler.getGameCamera().getyOffset()), width/2, height/2 , null);
    }
}

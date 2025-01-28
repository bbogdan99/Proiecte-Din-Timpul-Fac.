package work;

import java.awt.*;

public class Rock extends StaticEntity
{

    protected final int MaxHits = 3;
    private int currentHits;
    private final int SPEED = 500;
    private long ActionTimer, lastTime;

    public Rock(Handler handler, float x, float y)
    {
        super(handler,x,y,Tile.TILEWIDTH, Tile.TILEHEIGHT);
        currentHits=0;
        ActionTimer=0;
        lastTime=System.currentTimeMillis();
        bounds = new Rectangle(5,12,100,100);
    }

    @Override
    public void tick()
    {
        ActionTimer+=System.currentTimeMillis()-lastTime;
        lastTime=System.currentTimeMillis();
        float x1,x2, y1,y2;
        x1=x-handler.getGameCamera().getxOffset()+width;
        y1=x-handler.getGameCamera().getyOffset()+height;
        y2=handler.getGame().getHeight()/2;
        x2=handler.getGame().getWidth()/2;
        float xFin =(x2-x1)*(x2-x1); float yFin= (y2-y1)*(y2-y1);
        int test = (int)(Math.sqrt(xFin + yFin));
        //System.out.println(test);
        if (test<110 && currentHits<3)
        {
            //System.out.println("ESTI APROAPE!" + test);
            if (ActionTimer>600)
            {
                if (handler.getKeyManager().act)
                {
                    if (currentHits < MaxHits)
                        currentHits ++;
                }
                ActionTimer=0;
            }
        }
        if (currentHits==3)
        {
            currentHits=4;
            handler.getWorld().getEntityManager().addEntity(new RockResource(handler,x ,y , 64,64));
            health=0;
        }
    }

    @Override
    public void render(Graphics g)
    {
        //System.out.println(collidable);
        if (currentHits==0)
        {
            g.drawImage(Assets.rock1, (int) (x - handler.getGameCamera().getxOffset()),
                    (int) (y - handler.getGameCamera().getyOffset()), width * 2, height * 2, null);
        }
        if (currentHits==1)
        {
            g.drawImage(Assets.rock2, (int) (x - handler.getGameCamera().getxOffset()),
                    (int) (y - handler.getGameCamera().getyOffset()), width * 2, height * 2, null);
        }
        if (currentHits==2)
        {
            g.drawImage(Assets.rock3, (int) (x - handler.getGameCamera().getxOffset()),
                    (int) (y - handler.getGameCamera().getyOffset()), width * 2, height * 2, null);
        }
    }
}

package work;

public abstract class Creature extends Entity
{

    public static final float DEF_SPEED=3;
    public static final int DEF_CREATURE_WIDTH=64;
    public static final int DEF_CREATURE_HEIGHT=64;


    protected float speed;
    protected float xMove, yMove;

    public float getxMove() {
        return xMove;
    }

    public void setxMove(float xMove) {
        this.xMove = xMove;
    }

    public float getyMove() {
        return yMove;
    }

    public void setyMove(float yMove) {
        this.yMove = yMove;
    }

    public Creature(Handler handler,float x, float y, int width, int height)
    {
        super(handler, x,y, width, height);
        health=DEF_HEALTH;
        speed=DEF_SPEED;
        xMove=0;
        yMove=0;
    }

    public void move()
    {
        if (!checkCollision(xMove,0f))
            moveX();
        if (!checkCollision(0f,yMove))
            moveY();
    }

    public void moveX()
    {
        if (xMove>0)
        {
            int tx = (int) (x+xMove + bounds.x + bounds.width)/Tile.TILEWIDTH;
            if (!tileCollision(tx, (int) (y+bounds.y)/Tile.TILEHEIGHT)
                    && !tileCollision(tx, (int) (y+bounds.y+bounds.height)/Tile.TILEHEIGHT))
            {
                x=x+xMove;
            }
        }else if (xMove<0)
        {
            int tx = (int) (x+xMove + bounds.x)/Tile.TILEWIDTH;
            if (!tileCollision(tx, (int) (y+bounds.y)/Tile.TILEHEIGHT)
                    && !tileCollision(tx, (int) (y+bounds.y+bounds.height)/Tile.TILEHEIGHT))
            {
                x=x+xMove;
            }
        }

    }
    public void moveY()
    {
        if (yMove<0)
        {
            int ty = (int) (y+yMove + bounds.y)/Tile.TILEHEIGHT;
            if (!tileCollision((int)(x+bounds.x)/Tile.TILEWIDTH,ty  )
                    && !tileCollision( (int) (x+bounds.x+bounds.width)/Tile.TILEWIDTH, ty ))
            {
                y=y+yMove;
            }
        }
        else if (yMove>0)
        {
            int ty = (int) (y+yMove + bounds.y+bounds.height)/Tile.TILEHEIGHT;
            if (!tileCollision((int)(x+bounds.x)/Tile.TILEWIDTH,ty  )
                    && !tileCollision( (int) (x+bounds.x+bounds.width)/Tile.TILEWIDTH, ty ))
            {
                y=y+yMove;
            }
        }
    }

    protected boolean tileCollision(int x, int y)
    {
        return handler.getWorld().getTile(x,y).isSolid();
    }


    public int getHealth() {
        return health;
    }

    public void setHealth(int health) {
        this.health = health;
    }

    public float getSpeed() {
        return speed;
    }

    public void setSpeed(float speed) {
        this.speed = speed;
    }
}

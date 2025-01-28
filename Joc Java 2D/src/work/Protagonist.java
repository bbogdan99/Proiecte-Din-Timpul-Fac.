package work;

import java.awt.*;
import java.awt.image.BufferedImage;

public class Protagonist extends Creature
{
    private ProtagonistMovementAnimation hero_left, hero_right, hero_up;

    private int logResource, rockResource;

    public Protagonist(Handler handler, float x, float y) {

        super(handler, x, y, Creature.DEF_CREATURE_WIDTH, Creature.DEF_CREATURE_HEIGHT);
        hero_left = new ProtagonistMovementAnimation(500, Assets.hero_left1, Assets.hero_left2);
        hero_right = new ProtagonistMovementAnimation(500, Assets.hero_right1, Assets.hero_right2);
        hero_up = new ProtagonistMovementAnimation(500, Assets.hero_up1, Assets.hero_up2);

        logResource=0;
        rockResource=0;
        bounds = new Rectangle(13,8,35,49);
    }

    public void logResourceInc()
    {
        logResource++;
    }
    public void rockResourceInc()
    {
        rockResource++;
    }
    public int getLogResource() {
        return logResource;
    }
    public void setLogResource(int logResource) {
        this.logResource = logResource;
    }
    public int getRockResource() {
        return rockResource;
    }
    public void setRockResource(int rockResource) {
        this.rockResource = rockResource;
    }

    @Override
    public void tick()
    {
        hero_left.tick();
        hero_right.tick();
        hero_up.tick();
        getInput();
        move();
        handler.getGameCamera().centerOnEntity(this);
        System.out.println(getLogResource() + " " + getRockResource());
    }

    private void getInput()
    {
        xMove=0;
        yMove=0;

        if (handler.getKeyManager().up)
            yMove=-speed;
        if (handler.getKeyManager().down)
            yMove=speed;
        if (handler.getKeyManager().right)
            xMove=speed;
        if (handler.getKeyManager().left)
            xMove=-speed;
    }
    @Override
    public void render(Graphics g)
    {
        g.drawImage(getCurrentAnimationFrame(),(int)(x-handler.getGameCamera().getxOffset()),(int)(y-handler.getGameCamera().getyOffset()),width, height,null);
    }

    private BufferedImage getCurrentAnimationFrame()
    {
        if (xMove < 0)
            return hero_left.getCurrentFrame();
        if (xMove > 0 )
            return hero_right.getCurrentFrame();
        return hero_up.getCurrentFrame();
    }
}

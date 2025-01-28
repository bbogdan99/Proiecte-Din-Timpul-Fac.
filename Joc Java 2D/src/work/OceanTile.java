package work;

import java.awt.*;
import java.awt.image.BufferedImage;

public class OceanTile extends Tile
{
    private WaterChangeAnimation ActiveChange; //= new WaterChangeAnimation(500, Assets.water1, Assets.water2,
    //Assets.water3, Assets.water4);

    public OceanTile(int id)
    {
        super(Assets.water5, id);
        ActiveChange = new WaterChangeAnimation(500, Assets.water5, Assets.water6,
                Assets.water7, Assets.water8);
    }
    @Override
    public boolean isSolid()
    {
        return true;
    }

    @Override
    public void render(Graphics g, int x, int y)
    {
        g.drawImage(ActiveChange.getCurrentFrame(), x, y, TILEWIDTH, TILEHEIGHT, null);
    }
}

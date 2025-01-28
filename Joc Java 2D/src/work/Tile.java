package work;

import java.awt.*;
import java.awt.image.BufferedImage;

public class Tile
{
    public static Tile[] tiles=new Tile[256];
    public static Tile grassTile = new GrassTile(0);
    public static Tile sandTile = new SandTile(1);
    public static Tile wallTile = new WallTile(2);
    public static Tile waterTile = new WaterTile(3);
    public static Tile oceanTile = new OceanTile(4);

    public static final int TILEWIDTH=64, TILEHEIGHT=64;

    protected BufferedImage texture;
    protected int id;

    //^de schimbat!!!!
    public Tile(BufferedImage texture, int id)
    {
        this.texture=texture;
        this.id=id;

        tiles[id]=this;
    }
    public void tick()
    {

    }
    public void render(Graphics g, int x, int y)
    {
        g.drawImage(texture, x, y, TILEWIDTH, TILEHEIGHT, null);
    }

    public boolean isSolid()
    {
        return false;
    }

    public int getId()
    {return id;}
}

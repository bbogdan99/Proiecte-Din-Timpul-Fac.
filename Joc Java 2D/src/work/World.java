package work;

import java.awt.*;
import java.io.FileReader;

public class World
{
    private Handler handler;
    private int width, height;
    private int [][] tiles;
    //private int[][] entities;

    private EntityManager entityManager;

    public int getSpawnX() {
        return spawnX;
    }

    public int getSpawnY() {
        return spawnY;
    }

    private int spawnX, spawnY;

    public World(Handler handler,String path)
    {
        this.handler = handler; loadWorld(path);
        entityManager = new EntityManager(handler, new Protagonist(handler, 200,200));

        entityManager.getProtagonist().setX(spawnX*64);
        entityManager.getProtagonist().setY(spawnY*64);
        entityManager.addEntity(new Tree(handler, 64*2, 64*3));
        entityManager.addEntity(new Tree(handler, 64*5, 64*5));
        entityManager.addEntity(new Rock(handler, 64*8, 64*9));
    }

    public EntityManager getEntityManager() {
        return entityManager;
    }

    public void tick()
    {
        entityManager.tick();
    }
    public void render(Graphics g)
    {
        for (int i = 0; i < width; i++)
        {
            for (int j=0;j<height;j++)
            {
                getTile(i,j).render(g,(int)(i* Tile.TILEWIDTH - handler.getGameCamera().getxOffset()),
                        (int)(j*Tile.TILEHEIGHT - handler.getGameCamera().getyOffset()));
            }
        }
        entityManager.render(g);
    }

    public Tile getTile(int x, int y)
    {
        if (x<0 || y<0 || x>=width ||y>=height)
            return Tile.wallTile;

        Tile t = Tile.tiles[tiles[x][y]];
        if (t==null)
            return Tile.grassTile;
        return t;
    }

    private void loadWorld(String path)
    {
        /*width = 11;
        height = 11;
        tiles = new int[width][height];
        for(int i = 0; i < width; i++)
        {
            for(int j = 0; j < height; j++)
            {
                tiles[i][j] = TempMap(i, j);
            }
        }
        */
        String file = Read.loadFileAsString(path);
        String[] tokens = file.split("\\s+");
        width=Read.parseInt(tokens[0]);
        height=Read.parseInt(tokens[1]);
        spawnX=Read.parseInt(tokens[2]);
        spawnY=Read.parseInt(tokens[3]);

        tiles = new int[width][height];
        for (int i=0;i<width;i++)
        {
            for (int j=0;j<height;j++)
                tiles[i][j]=Read.parseInt(tokens[(i+j*width)+4]);
        }

        /*entities = new int[width][height];
        for (int i=0;i<width;i++)
        {
            for (int j =0;j<height;j++)
                entities[i][j]=Read.parseInt(tokens[(i+j*width)+4+width*height]);
        }*/
    }

    private int TempMap(int i, int j)
    {
        final int map[][] = {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        };
        return map[i][j];
    }
}

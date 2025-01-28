package work;

import java.awt.*;

public class GameState extends State
{
    //private Protagonist protagonist;
    private World world;
    //private Tree tree, tree2;

    public GameState(Handler handler)
    {
        super(handler);

        world = new World(handler,"res/worlds/world1.txt");
        handler.setWorld(world);
        //game.getGameCamera().move(0,0);
        //protagonist=new Protagonist(handler, world.getSpawnX()*64,world.getSpawnY()*64);
        //tree=new Tree(handler, 5*64, 5*64);
        //tree2=new Tree(handler, 8*64, 8*64);
    }

    @Override
    public void tick()
    {
        world.tick();
        //tree.tick();
        //tree2.tick();
        //protagonist.tick();
        //game.getGameCamera().move(1,1);
    }
    @Override
    public void render(Graphics g)
    {
        //g.drawImage(Assets.grass, 0, 0, null);
        world.render(g);
        //tree.render(g);
        //tree2.render(g);
        //protagonist.render(g);

    }
}

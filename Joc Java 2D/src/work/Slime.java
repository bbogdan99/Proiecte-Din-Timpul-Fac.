package work;

import java.awt.*;

public class Slime extends Creature
{
    private Game game;
    public Slime(Handler handler, float x, float y)
    {
        super(handler, x,y, Creature.DEF_CREATURE_WIDTH, DEF_CREATURE_WIDTH);
        //this.game=game;
    }

    @Override
    public void tick() {

    }

    @Override
    public void render(Graphics g) {

    }
}

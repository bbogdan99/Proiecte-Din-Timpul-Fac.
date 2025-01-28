package work;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class KeyManager implements KeyListener
{

    private boolean[] keys;

    public boolean up,down,left,right;

    public boolean act;

    public KeyManager()
    {
        keys = new boolean[256];
    }

    public void tick()
    {
        up = keys[KeyEvent.VK_W];
        down = keys[KeyEvent.VK_S];
        left=keys[KeyEvent.VK_A];
        right = keys[KeyEvent.VK_D];

        act = keys[KeyEvent.VK_F];
    }
    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e)
    {
        keys[e.getKeyCode()]=true;
        //System.out.println("pressed!");
    }

    @Override
    public void keyReleased(KeyEvent e) {
        keys[e.getKeyCode()]=false;
    }
}

package work;

//import java.lang.*;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.awt.image.BufferedImage;

public class Game implements Runnable
{
    private Display display;
    public int width, height;
    private boolean running = false;
    public String title;

    private Thread thread;

    private BufferStrategy bs;
    private Graphics g;

    private GameCamera gameCamera;

    public State gameState;
    public State menuState;
    private State rulesState;

    private KeyManager keyManager;
    private MouseManager mouseManager;

    private Handler handler;

    public Game(String title, int width, int height)
    {
        this.width=width;
        this.height=height;
        this.title=title;
        keyManager= new KeyManager();
        //display=new Display(title, width, height);
        mouseManager=new MouseManager();
    }

    private void init()
    {
        display=new Display(title, width, height);
        display.getFrame().addKeyListener(keyManager);
        display.getFrame().addMouseListener(mouseManager);
        display.getFrame().addMouseMotionListener(mouseManager);
        display.getCanvas().addMouseListener(mouseManager);
        display.getCanvas().addMouseMotionListener(mouseManager);
        Assets.init();

        gameCamera=new GameCamera(this,0,0);
        handler = new Handler(this);
        //test
        //testImage=ImageLoader.loadImage("/textures/imag.png");
        //test = ImageLoader.loadImage("/textures/imag.png");
        //sheet = new SpriteSheet(test);
        gameState = new GameState(handler);
        //menuState =...
        //rulesState=...
        menuState = new MenuState(handler);
        State.setState(menuState);
    }

    //int x=0;
    private void tick()
    {
        keyManager.tick();
        if (State.getState()!=null)
            State.getState().tick();
    }

    private void render()
    {
        bs = display.getCanvas().getBufferStrategy();
        if (bs == null)
        {
            display.getCanvas().createBufferStrategy(3);
            return;
        }
        g = bs.getDrawGraphics();
        //clear
        g.clearRect(0,0,width,height);
        //de sters! draw here

        if (State.getState()!=null)
            State.getState().render(g);

        //g.drawImage(Assets.grass, 10, 10, null);
        //g.drawImage(Assets.sand, 100, 100, null);
        //g.drawImage(sheet.crop(0,0,64,64),5,5,null);
        //g.drawImage(sheet.crop(64,64,64,64), 100,100,null);
        //g.drawImage(testImage,10,10,null);
        //g.fillRect(0,0,width,height);
        //de sters! end draw here
        bs.show();
        g.dispose();
    }

    public void run()
    {
        init();

        FpsTimer timer = new FpsTimer(60);
        while (running)
        {
            if (timer.check())
                tick();
            render();
        }

        stop();
    }

    public KeyManager getKeyManager()
    {
        return keyManager;
    }

    public MouseManager getMouseManager() {return mouseManager;}

    public GameCamera getGameCamera(){
        return gameCamera;
    }

    public int getWidth()
    {
        return width;
    }

    public int getHeight()
    {
        return height;
    }

    public synchronized void start()
    {
        if (running)
            return;
        running=true;
        thread = new Thread(this);
        thread.start();
    }

    public synchronized void stop()
    {
        if (!running)
            return;
        running=false;
        try
        {
            thread.join();
        } catch(InterruptedException e)
        {
            e.printStackTrace();
        }
    }
}

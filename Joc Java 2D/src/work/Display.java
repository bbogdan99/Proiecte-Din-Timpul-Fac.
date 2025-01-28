package work;

import javax.swing.JFrame;
import java.awt.Canvas;
import java.awt.Dimension;

public class Display
{
    private JFrame frame;
    private String titlu;
    private int width;
    private int height;

    private Canvas canvas;

    public Display(String titlu, int width, int height)
    {
        this.titlu=titlu;
        this.width=width;
        this.height=height;
        //frame=null;
        createDisplay();
    }

    private void createDisplay()
    {
        frame = new JFrame(titlu);
        frame.setSize(width, height);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        canvas = new Canvas();
        canvas.setPreferredSize(new Dimension (width, height));
        canvas.setMaximumSize(new Dimension(width, height));
        canvas.setMinimumSize(new Dimension(width, height));
        canvas.setFocusable(false);

        frame.add(canvas);
        frame.pack();
    }

    public Canvas getCanvas()
    {
        return canvas;
    }
    public JFrame getFrame() { return frame; }
}

package work;

import java.awt.image.BufferedImage;

//imagini/sunete/etc aici

public class Assets
{
    public static BufferedImage hero;
    public static BufferedImage slime;
    public static BufferedImage dwarf;

    public static BufferedImage grass, sand;
    public static BufferedImage wall;

    public static BufferedImage hero_left1, hero_left2;
    public static BufferedImage hero_right1, hero_right2;
    public static BufferedImage hero_up1, hero_up2;
    public static BufferedImage hero_up_static, hero_left_static, hero_right_static;

    public static BufferedImage tree1,tree2,tree3;
    public static BufferedImage rock1,rock2,rock3;

    public static BufferedImage water1,water2,water3,water4,water5,water6,water7,water8;

    public static BufferedImage start[], exit[];

    public static BufferedImage rockResource,logResource;

    private static final int width = 64, height =64;

    public static void init()
    {
        SpriteSheet sheet = new SpriteSheet (ImageLoader.loadImage("/textures/coliziuni.png"));
        grass = sheet.crop(0, 0, width, height);
        //non coliziuni + non animatii
        sand = sheet.crop(width, 0, width, height);
        wall = sheet.crop(width*2, 0, width, height);
        //coliziuni + non animatii

        water1 = sheet.crop(width*3, 0, width, height);
        water2 = sheet.crop(width*4, 0, width, height);
        water3 = sheet.crop(width*5, 0, width, height);
        water4 = sheet.crop(width*6, 0, width, height);
        water5 = sheet.crop(width*7, 0, width, height);
        water6 = sheet.crop(width*8, 0, width, height);
        water7 = sheet.crop(width*9, 0, width, height);
        water8 = sheet.crop(width*10, 0, width, height);
        //coliziuni + animatii
        hero = sheet.crop(width*0, height, width, height);
        hero_left1 = sheet.crop(width*1, height, width, height);
        hero_left2 = sheet.crop(width*2, height, width,height);
        hero_right1 = sheet.crop(width*3,height,width,height);
        hero_right2 = sheet.crop(width*4,height,width,height);
        hero_up1 = sheet.crop(width*5,height,width,height);
        hero_up2 = sheet.crop(width*6,height,width,height);
        //erou animatii
        tree1=sheet.crop(width*0,height*2,width*2,height*2);
        tree2=sheet.crop(width*2,height*2,width*2,height*2);
        tree3=sheet.crop(width*4,height*2,width*2,height*2);
        //copac stari
        start= new BufferedImage[2];
        exit = new BufferedImage[2];
        start[0]=sheet.crop(0, height*4, 400, 100);
        start[1]=sheet.crop(400,height*4,400,100);
        exit[0]=sheet.crop(0,height*4 +100, 400, 100);
        exit[1]=sheet.crop(400, height*4 +100, 400, 100);
        //butoane meniu
        rockResource=sheet.crop(width*6,height*2, 32,32);
        logResource = sheet.crop(width*6,height*2+32,32,32);

        rock1=sheet.crop(width*6+32,height*2,width*2, height*2);
        rock2=sheet.crop(width*8+32,height*2,width*2, height*2);
        rock3=sheet.crop(width*10+32,height*2,width*2, height*2);
        //hero_left1 = sheet.crop(width* 0, )
    }
}

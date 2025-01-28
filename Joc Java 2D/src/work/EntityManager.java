package work;

import java.awt.*;

public class EntityManager
{
    private Handler handler;
    private Protagonist protagonist;
    private Entity[] entities;
    private int size;

    public Handler getHandler() {
        return handler;
    }

    public void setHandler(Handler handler) {
        this.handler = handler;
    }

    public Protagonist getProtagonist() {
        return protagonist;
    }

    public void setProtagonist(Protagonist protagonist) {
        this.protagonist = protagonist;
    }

    public Entity[] getEntities() {
        return entities;
    }

    public void setEntities(Entity[] entities) {
        this.entities = entities;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public EntityManager(Handler handler, Protagonist protagonist)
    {
        this.handler=handler;
        this.protagonist=protagonist;
        entities = new Entity[100];
        size=0;
        addEntity(protagonist);
    }

    public void tick()
    {
        for (Entity entity : entities)
        {
            if (entity != null)
            {
                entity.tick();
            }
        }
    }
    public void render(Graphics g)
    {
        for (Entity entity : entities) {
            if (entity != null && entity!=protagonist)
            {
                entity.render(g);
            }
            protagonist.render(g);
        }
    }
    public void addEntity(Entity e)
    {
        entities[size]=e;
        size++;
    }
    public void deleteEntity(Entity e)
    {
        e=null;
    }

}

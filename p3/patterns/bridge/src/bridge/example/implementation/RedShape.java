package bridge.example.implementation;

public class RedShape implements DrawApi {

    @Override
    public void drawCircle(int x, int y, int radius) {
        System.out.println("Draw Red Circle in x:"+x+", y:"+y+", radius:"+radius);

    }

    @Override
    public void drawSquare(int x, int y, int height, int width) {
        System.out.print("Draw Red Square in x:"+x+", y:"+y);
        System.out.println(" with width:"+width+" and height:"+height);
    }

}

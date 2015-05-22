package bridge.example.implement;

public class GreenShape implements DrawApi {

    @Override
    public void drawCircle(int x, int y, int radius) {
        System.out.println("Draw Green Circle in x:"+x+", y:"+y+", radius:"+radius);

    }

    @Override
    public void drawSquare(int x, int y, int height, int width) {
        System.out.print("Draw Green Square in x:"+x+", y:"+y);
        System.out.println(" with width:"+width+" and height:"+height);
        
    }

}

package bridge.example.implement;

public class RedCircle implements DrawApi {

    @Override
    public void drawCircle(int x, int y, int radius) {
        System.out.println("Draw Red Circle in x:"+x+", y:"+y+", radius:"+radius);

    }

}

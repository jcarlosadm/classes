package bridge.example.abstraction;

import bridge.example.implement.DrawApi;

public class Circle extends Shape {

    private int x, y, radius;
    
    public Circle(int x, int y, int radius, DrawApi drawApi) {
        super(drawApi);
        this.x = x;
        this.y = y;
        this.radius = radius;
    }
    
    @Override
    public void draw() {
        drawApi.drawCircle(this.x, this.y, this.radius);
    }
}

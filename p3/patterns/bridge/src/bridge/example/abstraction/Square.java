package bridge.example.abstraction;

import bridge.example.implementation.DrawApi;

public class Square extends Shape{

    private int x, y, width, height;
    
    public Square(int x, int y, int height, int width, DrawApi drawApi) {
        super(drawApi);
        this.x = x;
        this.y = y;
        this.height = height;
        this.width = width;
    }

    @Override
    public void draw() {
        this.drawApi.drawSquare(x, y, height, width);
    }

}

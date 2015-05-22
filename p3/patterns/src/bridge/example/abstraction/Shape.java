package bridge.example.abstraction;

import bridge.example.implement.DrawApi;

public abstract class Shape {

    protected DrawApi drawApi;
    
    public Shape(DrawApi drawApi) {
        this.drawApi = drawApi;
    }
    
    public abstract void draw();
    
    public abstract void switchColor(DrawApi drawApi);
}

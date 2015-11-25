package shape.cache;

import java.util.Hashtable;
import java.util.Map;

import shape.Circle;
import shape.Rectangle;
import shape.Shape;
import shape.Square;

public class ShapeCache {
    private static Map<String, Shape> shapeMap = new Hashtable<>();
    
    public static Shape getShape(String shapeId){
        Shape cachedShape = shapeMap.get(shapeId);
        return (Shape) cachedShape.clone();
    }
    
    public static void loadCache() {
        Circle circle = new Circle();
        circle.setId("1");
        shapeMap.put(circle.getId(), circle);
        
        Square square = new Square();
        square.setId("2");
        shapeMap.put(square.getId(), square);
        
        Rectangle rectangle = new Rectangle();
        rectangle.setId("3");
        shapeMap.put(rectangle.getId(), rectangle);
    }
}

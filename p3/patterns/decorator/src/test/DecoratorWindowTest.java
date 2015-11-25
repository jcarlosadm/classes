package test;

import decorator.HorizontalScrollBar;
import decorator.VerticalScrollDecorator;
import decorator.window.SimpleWindow;
import decorator.window.Window;

public class DecoratorWindowTest {
    public static void main(String[] args) {
        
        Window simpleWindow = new SimpleWindow();
        Window decoratedWindow1 = new VerticalScrollDecorator(simpleWindow);
        Window decoratedWindow2 = new HorizontalScrollBar(decoratedWindow1);
        
        System.out.println(decoratedWindow2.getDescription());
        System.out.println(decoratedWindow1.getDescription());
        System.out.println(simpleWindow.getDescription());
    }
}

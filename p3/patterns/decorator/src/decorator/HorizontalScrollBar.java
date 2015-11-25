package decorator;

import decorator.window.Window;

public class HorizontalScrollBar extends WindowDecorator {

    public HorizontalScrollBar(Window windowToBeDecorated) {
        super(windowToBeDecorated);
    }
    
    @Override
    public void draw() {
        super.draw();
        this.drawHorizontalScrollBar();
    }

    private void drawHorizontalScrollBar() {
        System.out.println("Draw horizontal scroll bar");
    }
    
    @Override
    public String getDescription() {
        return super.getDescription()+", including horizontal scroll bar";
    }

}

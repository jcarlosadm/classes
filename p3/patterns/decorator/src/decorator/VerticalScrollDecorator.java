package decorator;

import decorator.window.Window;

public class VerticalScrollDecorator extends WindowDecorator {

    public VerticalScrollDecorator(Window windowToBeDecorated) {
        super(windowToBeDecorated);
    }
    
    @Override
    public void draw() {
        super.draw();
        this.drawVerticalScrollBar();
    }

    private void drawVerticalScrollBar() {
        System.out.println("draw vertical scroll bar");
    }
    
    @Override
    public String getDescription() {
        return super.getDescription() + ", including vertical scrollbar";
    }

}

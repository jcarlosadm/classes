package decorator.window;

public class SimpleWindow implements Window {

    @Override
    public void draw() {
        System.out.println("draw the simple window");
    }

    @Override
    public String getDescription() {
        return "simple window";
    }

}

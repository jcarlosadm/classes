package command;

import light.Light;

public class LightOn implements Command {

    private Light light;
    
    public LightOn(Light light) {
        this.light = light;
    }
    
    @Override
    public void execute() {
        this.light.turnOn();
    }

}

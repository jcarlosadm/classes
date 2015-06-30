package command;

import light.Light;

public class LightOff implements Command {

    private Light light;
    
    public LightOff(Light light) {
        this.light = light;
    }
    
    @Override
    public void execute() {
        this.light.turnOff();
    }

}

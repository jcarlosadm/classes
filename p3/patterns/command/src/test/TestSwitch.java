package test;

import command.Command;
import command.LightOff;
import command.LightOn;
import light.Light;

public class TestSwitch {
    public static void main(String[] args) {
        /**
        if(args.length != 1){
            System.err.println("Argument \"ON\" or \"OFF\" is required.");
            System.exit(-1);
        }*/
        
        Light light = new Light();
        Command lightOn = new LightOn(light);
        Command lightOff = new LightOff(light);
        
        Switch sw = new Switch();
        sw.addCommand("ON", lightOn);
        sw.addCommand("OFF", lightOff);
        
        String exec = "OFF";
        
        if(sw.hasCommand(exec)){
            sw.executeCommand(exec);
        } else {
            System.err.println("Argument \"ON\" or \"OFF\" is required.");
            System.exit(-1);
        }
        
        /**
        if(sw.hasCommand(args[0])){
            sw.executeCommand(args[0]);
        } else {
            System.err.println("Argument \"ON\" or \"OFF\" is required.");
            System.exit(-1);
        }*/
    }
}

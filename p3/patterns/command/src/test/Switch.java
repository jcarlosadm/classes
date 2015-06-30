package test;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import command.Command;


public class Switch {
    private Map<String, Command> mapCommand = new HashMap<>();
    private List<Command> history = new ArrayList<>();
    
    public void addCommand(String key,Command command){
        this.mapCommand.put(key, command);
    }
    
    public boolean hasCommand(String key){
        return this.mapCommand.containsKey(key);
    }
    
    public void executeCommand(String key){
        if(this.mapCommand.containsKey(key)){
            this.history.add(this.mapCommand.get(key));
            this.mapCommand.get(key).execute();
        }
    }
}

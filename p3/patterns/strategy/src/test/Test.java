package test;

import strategy.HappyHourStrategy;
import strategy.NormalStrategy;

public class Test {
    public static void main(String[] args) {
        Customer a = new Customer();
        a.setStrategy(new NormalStrategy());
        a.add(1.2, 1);
        a.add(2.3, 4);
        a.printBill();
        
        a.setStrategy(new HappyHourStrategy());
        a.printBill();
    }
}

package test;

import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.List;

import strategy.BillingStrategy;
import strategy.NullStrategy;

public class Customer {
    private List<Double> drinks;
    private BillingStrategy strategy = new NullStrategy();
    
    public Customer() {
        this.drinks = new ArrayList<Double>();
    }
    
    public void add(double price, int quantity){
        this.drinks.add(price*quantity);
    }
    
    public void printBill(){
        NumberFormat formatter = new DecimalFormat("#0.00");
        System.out.println("Total due: $ " + formatter.format(this.strategy.sum(drinks)));
    }
    
    public void setStrategy(BillingStrategy strategy){
        this.strategy = strategy;
    }
}

package strategy;

import java.util.List;

public class NullStrategy implements BillingStrategy {

    @Override
    public double sum(List<Double> drinks) {
        double sum = 0;
        for (Double drink : drinks) {
            sum += drink;
        }
        return sum;
    }

}

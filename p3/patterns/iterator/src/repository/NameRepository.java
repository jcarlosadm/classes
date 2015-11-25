package repository;

import iterator.Container;
import iterator.Iterator;

public class NameRepository implements Container {

    private String[] names = { "Robert", "John", "Julie", "Laura" };

    @Override
    public Iterator getIterator() {
        return new NameIterator();
    }

    private class NameIterator implements Iterator {

        private int index = 0;

        @Override
        public boolean hasNext() {
            if (this.index < names.length) {
                return true;
            }

            return false;
        }

        @Override
        public Object next() {
            if (this.hasNext()) {
                return names[index++];
            }
            return null;
        }

    }

}

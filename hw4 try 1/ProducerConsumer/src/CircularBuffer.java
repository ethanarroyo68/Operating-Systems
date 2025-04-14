public class CircularBuffer {
    // Class variable declarations
    private double[] circularBuffer;
    private int head, tail, capacity, count;

    public CircularBuffer(int capacity) { // Constructor
        this.head = 0;
        this.tail = 0;
        this.count = 0;
        this.capacity = capacity;
        this.circularBuffer = new double[capacity];
    }

    public synchronized double remove() {
        while (count == 0) { // Meaning the buffer is empty
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        double item = circularBuffer[head]; // Get the item from the head and consume
        head = (head + 1) % capacity; // Move the head to the next spot
        count--;
        notify();

        return item; // Return the consumed items
    }

    public synchronized void add(double item) {
        while (count == capacity) { // Meaning the buffer is full
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        circularBuffer[tail] = item; // Add a new item to the buffer, the actual producing
        tail = (tail + 1) % capacity; // Move the tail to next spot
        count++;
        notify();
    }

}

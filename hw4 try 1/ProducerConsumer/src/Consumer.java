class Consumer extends Thread {
    // Create buffer object
    private CircularBuffer buffer;

    public Consumer(CircularBuffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        double bufferValueCounter = 0;
        for (int i = 1; i <= 1000000; i++) {
            double item = buffer.remove(); // Consume item
            bufferValueCounter += item;

            // Actual ouput
            if (i % 100000 == 0) {
                System.out.println("Consumer: Consumed " + i + " items, Cumulative value of consumed items=" + bufferValueCounter);
            }
        }
        System.out.println("Consumer: Finished consuming 1,000,000 items");
    }
}

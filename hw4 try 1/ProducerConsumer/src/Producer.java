class Producer extends Thread {
    // Create buffer
    private CircularBuffer buffer;

    public Producer(CircularBuffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        double bufferValueCounter = 0;
        for (int i = 1; i <= 1000000; i++) {
            double item = Math.random() * 100.0; // Generate random number item
            buffer.add(item);
            bufferValueCounter += item;
            
            // Actual output
            if (i % 100000 == 0) {
                System.out.println("Producer: Generated " + i + " items, Cumulative value of generated items=" + bufferValueCounter);
            }
        }
        System.out.println("Producer: Finished generating 1,000,000 items");
    }
}

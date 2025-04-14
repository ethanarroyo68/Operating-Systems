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
            double item = Math.random() * 100.0;
            buffer.add(item);
            bufferValueCounter += item;

            // Actual output here
            if (i % 100000 == 0) {
                System.out.printf("Producer: Generated %d items, Cumulative value of generated items=%.6f\n", i,
                        bufferValueCounter);
            }
        }

        // Add termination signal only after completing the production
        buffer.terminate();
        System.out.println("Producer: Finished generating 1,000,000 items");
    }
}

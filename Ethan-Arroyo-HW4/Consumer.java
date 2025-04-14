class Consumer extends Thread {
    private CircularBuffer buffer;

    public Consumer(CircularBuffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        double bufferValueCounter = 0;
        int i = 0;
        while (true) {
            double item = buffer.remove();

            if (item == -1) { // Exit when termination signal is encountered
                break;
            }

            bufferValueCounter += item;
            i++;

            // Actual output here
            if (i % 100000 == 0) {
                System.out.printf("Consumer: Consumed %d items, Cumulative value of consumed items=%.6f\n", i,
                        bufferValueCounter);
            }
        }

        System.out.println("Consumer: Finished consuming 1,000,000 items");
    }

}

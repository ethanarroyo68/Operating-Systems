public class ProducerConsumer {
    public static void main(String[] args) {
        CircularBuffer buffer = new CircularBuffer(1000); // Designate capacity of 1000

        // Create both threasd
        Consumer consumer = new Consumer(buffer); 
        Producer producer = new Producer(buffer);

        // Start running both threads
        producer.start();
        consumer.start();

        try { // Wait for producer and consumer to finish, respectively
            producer.join();
            consumer.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Exiting!");
    }
}

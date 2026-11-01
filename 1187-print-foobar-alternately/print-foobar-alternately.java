import java.util.concurrent.Semaphore;

class FooBar {
    private int n;
    private final Semaphore semaphore1;
    private final Semaphore semaphore2;
    public FooBar(int n) {
        this.n = n;
        semaphore1 =new Semaphore(1);
        semaphore2 =new Semaphore(0);
        
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	semaphore1.acquire();
            printFoo.run();
            semaphore2.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            // printBar.run() outputs "bar". Do not change or remove this line.
            semaphore2.acquire();
        	printBar.run();
            semaphore1.release();
        }
    }
}
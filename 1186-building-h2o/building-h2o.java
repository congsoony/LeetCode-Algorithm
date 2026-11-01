class H2O {
    private volatile int cnt = 1;
    private Semaphore s1,s2;
    public H2O() {
        s1 =new Semaphore(2);
        s2 = new Semaphore(0);
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        s1.acquire();
        releaseHydrogen.run();
        cnt=(cnt+1)%3;
        if(cnt==2){
            s2.release();
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
        s2.acquire();
		releaseOxygen.run();
        cnt= (cnt+1)%3;
        s1.release();
        s1.release();
    }
}
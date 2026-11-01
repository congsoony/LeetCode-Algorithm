class ZeroEvenOdd {
    private int n;
    private boolean flag =true;
    Semaphore []s;
    public ZeroEvenOdd(int n) {
        this.n = n;
        s = new Semaphore[3];
        s[0]=new Semaphore(1);
        s[1]=new Semaphore(0);
        s[2]=new Semaphore(0);
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for(int i=0;i<n;i++){
            s[0].acquire();
            printNumber.accept(0);
            if(flag)
                s[1].release();
            else
                s[2].release();
        }
        
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for(int i =2;i<=n;i+=2){
            s[2].acquire();
            printNumber.accept(i);
            s[0].release();
            flag = true;

        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for(int i =1;i<=n;i+=2){
            s[1].acquire();
            printNumber.accept(i);
            flag = false;
            s[0].release();
        }
    }
}
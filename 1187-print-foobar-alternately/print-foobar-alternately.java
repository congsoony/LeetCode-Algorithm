

class FooBar {
    private int n;
    private boolean foo =true;
    public FooBar(int n) {
        this.n = n;
        
    }

    public synchronized void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo.run() outputs "foo". Do not change or remove this line.
            while(!foo){
                wait();
            }
        	printFoo.run();
            foo=false;
            notifyAll();

        }
    }

    public synchronized void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            // printBar.run() outputs "bar". Do not change or remove this line.
            while(foo){
                wait();
            }

           
        	printBar.run();
            foo = true;
            notifyAll();
        }
    }
}
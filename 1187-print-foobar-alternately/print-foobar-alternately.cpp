class FooBar {
private:
    int n;
    int turn;
    mutex m;
    condition_variable c;

public:
    FooBar(int n) {
        this->n = n;
        this->turn = 0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            while(turn == 1){
                c.wait(lock);
            }
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            turn = 1;
            c.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            while(turn == 0){
                c.wait(lock);
            }
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn = 0;
            c.notify_all();
        }
    }
};
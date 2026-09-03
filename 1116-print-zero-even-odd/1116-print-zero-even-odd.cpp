class ZeroEvenOdd {
    //std::vector<int> nums;
private:
    int n;
    int i=1;
    mutex mzero, meven, modd; 
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        meven.lock(); 
        modd.lock();
    }
    void zero(function<void(int)> printNumber) {
        bool run = true;
        while (run){
            
            mzero.lock(); 
            printNumber(0);

            run = i < n;

            if (i % 2 == 0) {meven.unlock();} 
            else {modd.unlock();}
        }
    }

    void even(function<void(int)> printNumber) {
        bool run = n>=2;
        while (run) {
            meven.lock();
            printNumber(i);
            i++;

            run = i < n;

            mzero.unlock(); 
        }
    }

    void odd(function<void(int)> printNumber) {
        bool run = n >=1;
        while (run) {
            modd.lock();
            printNumber(i);
            i++;

            run = i < n;

            mzero.unlock(); 
        }
    }
};
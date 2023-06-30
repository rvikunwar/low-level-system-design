// Low level design - strategy design pattern


// Startegy design patern is a behavioral pattern which allows us to define a set of classes
// for different scenarios which are independent to each other. And it provides an options 
// to the external client to use any of the class depending upon the situation/issue without 
// exposing any internal implementation of the used class (encapsualtion).  

// let's say you have a task to perform, but there are multiple ways to perform it depending upon 
// requirement and situation. Each approach have a special ability to solve issue that may or may 
// not arise while performing the task, so you want to have a flexibility to choose and switch 
// between approaches or strategies based on your needs. The startegy pattern allows us to do that. 
// It contains a set of strategies, each having a different approach for solving a problem. 
// It provides us an ability to select a strategy based upon requirements, easily switch between
// them without affecting any main core logic.

// The strategy pattern promotes code reusability, flexibilty, encapsulation. It provides freedom 
// to choose any of the strategy and switch between them without affecting underlying code. Basically 
// it is like a toolbox with different tools for different situation. We can take any tool depending 
// upon task and can switch tools if any requirement arises and at the same time we don't need to know 
// how those are build, just having a idea of how to use them will solve of our problem. 
   

#include <bits/stdc++.h>
using namespace std;

class PaymentStrategy {
    public:
        virtual void processPayment(const int amount) = 0;
};

class PaypalPaymentStrategy: public PaymentStrategy {
    public:
        void processPayment(const int amount) override { 
            // process the payment with paypal
        }
};

class UPIPaymentStrategy: public PaymentStrategy {
    public:
        void processPayment(const int amount) override {
            // process the payment with UPI
        }
};

class PaymentContext {
    PaymentStrategy* strategy;
    public:
        // polymorphism, using parent class pointer
        // to store derived class objects,
        // this helps us to switch between objects 
        // of differnt derived classes
        void setPaymentStrategy(PaymentStrategy* strategy){
            this->strategy = strategy;
        }

        void processPayment(const int amount){
            strategy->processPayment(amount);
        }
};


int main(){
    // client code/ external main logic 
    // for processing payment 

    PaymentContext paymentContext;
    
    // if user wants to pay using 
    // paypal then in this case we can  use
    // paypal strategy
    PaypalPaymentStrategy paypalStrategy;
    paymentContext.setPaymentStrategy(&paypalStrategy); 
    paymentContext.processPayment(100);

    // or let's say user wants to pay using
    // upi, then we can switch to upi strategy
    // without disrupting any ongoing flow
    UPIPaymentStrategy upiStrategy;
    paymentContext.setPaymentStrategy(&upiStrategy);
    paymentContext.processPayment(999);

    return 0;
}


#include <bits/stdc++.h>
using namespace std;


// Strategy interface
class CompressionStrategy {
    public:
        virtual void compressFile(const string& file) = 0;
}

//Concrete strategy
class ZIPCompressionStrategy: public CompressionStrategy {
    public:
        void compressFile(const string& file) override {
            cout<<"Compression of file using ZIP"<<endl;
        }
}


class RARCompressionStrategy: public CompressionStrategy {
    public:
        void compressFile(const string &file) override {
            cout<<"Compression of file using RAR"<<endl;
        }
}

// Context strategy
class CompressionContext {
    private:
        CompressionStrategy* strategy;

    public:
        void setCompressionStrategy(CompressionStrategy* strategy) {
            this->strategy = strategy;
        } 

        void compressFile(const string& file) {
            strategy->compressFile(file)
        }
}


// Client code 
int main() {
    CompressionContext compressionContext;
    RARCompressionStrategy rarStrategy;
    ZIPCompressionStrategy zipStrategy;

    compressionContext.setCompressionStrategy(&zipStrategy);
    compressionContext.compressFile("document.file");

    compressionContext.setCompressionStrategy(&rarStrategy);
    compressionContext.compressFile("document.file");

    return 0;
}
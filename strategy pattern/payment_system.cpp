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

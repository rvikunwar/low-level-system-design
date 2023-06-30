// 2. observer_pattern

// The observer pattern is another behavioral pattern that allows an object 
// (called as publisher/observable/subject) to notify a list of its 
// dependents called observers whenever there is any change in its state in the system.

// For example, let's say you have subscribed to a newsletter and you want to receive the 
// latest published newsletter whenever it's published. So here you can do one thing, you can constantly 
// keep on checking for any newly published newsletter and whenever there is one you can directly take it 
// from there, but this approach is time consuming and resource consuming.
// Another approach can be implemented from publisher side, we can make it a publisher job to notify each 
// and every subscriber regarding any new publishing. Publisher will notify its subscriber whenever there is new
// publication which removes the load from subscriber for constant checking and this way both publisher and 
// subscriber can focus on there job rather than indulging in each other logic or implementation promoting 
// loose coupling between the subject and it's observers.
// So, this is achieved by observer pattern, where publisher is the source and subscribers are the observers
// ,and source will maintain a list of it's observer and using this list it will notify observers whenever 
// there is any change.

// Some examples of Observer pattern where you might find it's usage:
// -Reactive Programming libraries (rxjs)
// -Pub-Sub (Publish-Subscribe) systems like apache kafka
// -MVC frameworks ASP.NET, Django, basically for communicating between model, view and controller

// Implementation of Observer pattern in C++ for a notification system (sending notification to users)
#include<bits/stdc++.h>
using namespace std;


//Observer interface
class Observer {
	public:
		virtual void update(const string& message) = 0;
};  


class NotificationService {
	private:
		//list of observers
		vector<Observer*> observers;

	public:
		//adds new observers or subscription
		void addObserver(Observer* o){
			observers.push_back(o);
		}

		//unsubscribe
		void removeObserver(Observer* o){
			auto it = find(observers.begin(), observers.end(), o);

			if(it != observers.end()){
				observers.erase(it);
			}
		}

		//notifies all the observers
		void notify(const string& message){
			for(auto it: observers){
				it->update(message);
			}
		}

		//implement logic/change state and then trigger notify method
		void sendMessage(const string& message){
			notify(message);
		}
};



class User: public Observer {
	private:
		string name;
	public:
		User(string name){
			this->name = name;
		}

		// overrides Observer update method and
		// here logic can be implement based upon the 
		// message received
		void update(const string& message) override {
			cout<<"User "<<name<<" received a notifictaion"<<endl;
			cout<<"Message: "<< message<<endl;
		}
};


int main(){

	// Creating notification service
	NotificationService notificationService;

	// Creating users
	User user1("Aman sharma");
	User user2("Rajat kohli");
	User user3("Sam karan");

	// Subscribe the users to the notification service
	// they will listens to any state change in notification 
	// service or any message
	notificationService.addObserver(&user1);
	notificationService.addObserver(&user2);

	//Sending a message from notification service to all the listeners
	//it will be presented to every subscribers(users)
	notificationService.sendMessage("Hi everyone");

	return 0;
}
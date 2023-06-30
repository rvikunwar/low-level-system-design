// observer_pattern
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

		// overrides Observer update methods and
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

	// Create users
	User user1("Aman sharma");
	User user2("Rajat kohli");
	User user3("Sam karan");

	// Subscribe the users to the notification service
	// they will listens to any state change in notification 
	// service or any message
	notificationService.addObserver(&user1);
	notificationService.addObserver(&user2);

	//Sending a message from notification service to all the listeners
	notificationService.sendMessage("Hi everyone");

	notificationService.removeObserver(&user1);

	return 0;
}
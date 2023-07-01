# Observer Pattern

The Observer Pattern is a behavioral design pattern that allows an object (called the publisher/observable/subject) to notify a list of its dependents called observers whenever there is any change in its state in the system.

## Overview

In this example, we will explore the Observer Pattern and implement notification system in C++, for sending notifications to users.

## Problem Statement

Let's consider a scenario where users subscribe to a newsletter and want to receive the latest published newsletter whenever it's available. One approach would be for the users to constantly check for any newly published newsletters, which can be time-consuming and resource-intensive.

## Solution

So here we can do one thing, users can constantly keep on checking for any newly published newsletter and whenever there is one you can directly take it from there, but this approach is naive, time consuming and resource consuming.
Another way to address the problem can be the Observer Pattern. In this pattern, the publisher takes the responsibility of notifying each subscriber whenever there is a new publication. This way, subscribers are relieved from the burden of constantly checking for updates. It promotes loose coupling between the publisher (source) and the subscribers (observers), allowing them to focus on their respective responsibilities.

## Examples of Observer Pattern

The Observer Pattern is commonly used in various scenarios, including:

- Reactive Programming libraries like RxJS.
- Pub-Sub (Publish-Subscribe) systems such as Apache Kafka.
- MVC frameworks like ASP.NET and Django, which facilitate communication between model, view, and controller.

## Usage

To implement the Observer Pattern in your own projects, follow these steps:

1. Define a publisher/observable/subject class that maintains a list of observers and provides methods to subscribe, unsubscribe, and notify observers.
2. Implement observer classes that define the actions to be taken when they are notified by the publisher.
3. Establish the necessary communication between the publisher and the observers.

## Implementation

The implementation details for the notification system using the Observer Pattern in C++ can be found in the [notification_system.cpp](./example.cpp) file.
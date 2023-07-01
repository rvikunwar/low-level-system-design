# Low-Level Design - Strategy Design Pattern

The Strategy Design Pattern is a behavioral pattern that allows us to define a set of classes for different scenarios, which are independent of each other. It provides an option to the external client to use any of the classes depending on the situation or issue without exposing the internal implementation of the used class (encapsulation).

## Overview

In this example, we will explore the Strategy Design Pattern, which provides a flexible approach for performing a task. We will define a set of strategies, each having a different approach for solving a problem. The client can choose and switch between strategies based on requirements without affecting the main core logic.

## Problem Statement

Let's consider a scenario where you have a task to perform, but there are multiple ways to perform it depending on the requirement and situation. Each approach has a special ability to solve issues that may or may not arise while performing the task. Therefore, you want the flexibility to choose and switch between approaches or strategies based on your needs.

## Solution

The Strategy Pattern provides a solution to the problem by offering a set of strategies, each with a different approach for solving a problem. The client can select a strategy based on requirements and easily switch between them without affecting the underlying code or core logic.

## Benefits of Strategy Design Pattern

The Strategy Design Pattern offers several benefits:

- Code reusability: The strategies can be reused across different parts of the system.
- Flexibility: The client can choose and switch between strategies as needed.
- Encapsulation: The internal implementation of each strategy is hidden from the client, promoting encapsulation and information hiding.

## Implementation

The implementation of the Strategy Design Pattern involves the following components:

1. Context: It represents the context or the object that uses the strategy. It contains a reference to the selected strategy and invokes the strategy's methods when necessary.
2. Strategy: It defines the interface or base class for all strategies. It declares the common methods that all strategies must implement.
3. Concrete Strategies: These are the specific strategies that provide different approaches to solve the problem. Each concrete strategy implements the methods defined by the strategy interface.

## Usage

To use the Strategy Design Pattern in your own projects, follow these steps:

1. Identify the problem or task that can have multiple approaches or strategies.
2. Define the strategy interface or base class that declares the common methods.
3. Implement the concrete strategies, each providing a different approach to solving the problem.
4. Create a context object that uses the strategy interface and contains a reference to the selected strategy.
5. Use the context object to invoke the appropriate strategy's methods based on the requirements.

## Examples

The Strategy Design Pattern is commonly used in various scenarios, including:

- Sorting algorithms: Different sorting strategies (e.g., Bubble Sort, Quick Sort, Merge Sort) can be implemented as strategies, allowing the client to choose the sorting algorithm based on the data and performance requirements.
- File compression utilities: Different compression algorithms (e.g., ZIP, GZIP, RAR) can be implemented as strategies, providing options for the user to choose the compression method.


## Implementation

The implementation details for the Strategy Pattern in C++ can be found in the [compression_system.cpp](./compression_system.cpp), [payment_system.cpp](./payment_system.cpp) file.
<style type="text/css">@import url(https://fonts.googleapis.com/css?family=Architects+Daughter)</style>
# Low-Level Design Patterns
<h1 style="font-family: Architects Daughter">ssssssssss</h1>
This repository contains a collection of low-level design patterns, along with examples and explanations. Each design pattern addresses a specific software design problem and provides a reusable solution that promotes code reusability, flexibility, and maintainability. ***Currently this blog is in progress and I have uploaded few things here and I will update this blog from time to time in future.***

## Decorator Pattern 
<img style="position: fixed; top: 0; right:0; width:200px; height: 60px;" src="./decorator pattern/decoratorpatternlogo.svg"/>
Decorator pattern is a structural pattern which is used to dynamically add new functionality and behaviour to an object without altering its source code.
This is usefull when you want to add new functionality on top of an object not on class, means if you want add new functionality to few objects of class rather than all objects then in that case this pattern could be usefull.

### Why decorator pattern ?
Let's consider an example:  Imagine you're looking to start a business selling various chai (tea) variants such as masala chai, tandoori chai, and kulhad chai. To efficiently handle orders for these chai variations, you want a smart system.

Initially, you started coding and created a base class called "Chai" and then derive subclasses from it to define the different chai variations. In this example, let's focus on three variants: masala chai, kulhad chai, and tandoori chai. So, you have three separate classes to manage these three variants.

However, as time goes on, customer preferences also evolves. Some customers request masala chai without sugar, while others want masala chai with extra sugar. There are also requests for kulhad chai without sugar, tandoori chai without milk, and many more variations.

To address these evolving demands, you start creating new classes inherited from the base "Chai" class. While this approach works, it begins to pose challenges as your chai menu expands. Imagine you have thousands of chai variations. In such a scenario, creating thousands of subclasses becomes impractical and leads to what is commonly referred to as the "explosion of classes" issue

![explosion of classes](./decorator%20pattern/explosion.svg)    

This problem can be effectively solved by applying the Decorator Pattern, which allows you to dynamically add and combine features (such as extra sugar, without milk, with mild etc.) without creating an extra number of subclasses.

In the Decorator Pattern, you start by defining a decorator class that inherits from the base "Chai" class and also takes chai object as a parameter. Then, you create additional decorator subclasses to define specific decorators for important chai variations like masala chai decorator, kulhad chai decorator, chai without milk decorator, chai without sugar decorator, and so on.

Let's consider an example: Suppose you receive an order for masala chai without milk and sugar. With the Decorator Pattern, you don't have to create a new class specifically for this variation. Instead, you can create a masala chai object and pass it through the chai without milk decorator, which handles all operations related to this particular decorator. Then, you can pass the same object through the chai without sugar decorator, resulting in an order for masala chai without milk and sugar, with all the necessary computations. This is commonly referred as **wrapping of object** with another object or function for adding new functionality and behaviour.

![wrappping](./decorator%20pattern/wrapper.svg)    

This approach eliminates the need to define numerous new classes for each possible chai variation, and importantly, it doesn't require any changes to the source code of the main "Chai" class. This flexibility and extensibility make the Decorator Pattern a powerful tool for managing complex and evolving class hierarchies.

![explosion of classes](./decorator%20pattern/decoratorpattern_example.svg)    

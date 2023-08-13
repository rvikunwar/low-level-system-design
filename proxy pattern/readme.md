# PROXY PATTERN
Proxy pattern is a structural pattern which wraps an entity and take control of it, and also adds additional functionality on top of it, It is used for various purposes -  lazy loading, logging, protecting and controlling data (protection), tracking, optimization (caching) and more.

## Why We Need the Proxy Pattern
Imagine you are implementing a feature that involves listing a collection of images on a web page. Let's say there are 100 images and some of them are of high resolution, which takes heavy toll on loading time and consumes significant memory. On the other hand, there are some lighter images that loads quickly and does not take much time and resources. Basically the general procedure will be as follows, first an API will be called, fetching the urls of all the 100 images.Upon a successfull response you extract the URLs and load them into the application. The images will try to load on the device simultaneously, making makes it challenging for the operating system to handle all of them concurrently.This in turn directly affects user experience. This approach is quite naive and brute force.

So, what can we done to improve this situation?

For optimization and better user experience, the best approach is to load the image only when user intends to view them, this approach is commonly known as lazy loading, is achieved by proxy pattern.

Our primary structure is designed to fetch images from a remote server and directly load them onto a user's device. we can encapsulate this structure and optimize our functionality using proxy pattern.

In the context of lazy loading, images are not loaded or remain inactive until they are specifically requested by the client. The proxy pattern takes charge here by ither preventing immediate image loading or deferring it until the client asks for it.

The client interacts with proxy, which acts as an intermediary helping the client to achieve what is expected from the original object. This interaction takes place through the same interface and channel that the client would use to access the real object. This way client doesn't even need to know whether they're interacting with actual object or its proxy.This is the key feature of proxy pattern. And when the time comes, the proxy smoothly takes on the responsibility of displaying or loading image when requested.

## Types of Proxy Pattern 
- remote proxy, A pattern used to facilitate communication between distributed components.
- virtual proxy, It provides a placeholder for another object to perform the same function with extra functionality
- protection proxy, A pattern which acts as an intermediary layer between the client and object, ensuring that only authorized client can interact with real object methods and properties.

## Scenarios where we need Proxy pattern
- **Virtual proxy - Lazy loading** Loading the resource only when requested.
- **Protection proxy - control and security** this can be used to prevent users from accessing resources that they don't have permission to access.
- **Caching and optimization**, a web browser can use caching proxy to store recently visited webpage. If user revisits a page, the broeser can serve the cached version, reducing page load time.
- **Remote proxy - Remote communication** Proxies can be to access remote server to access and manipulate resources
- **Monitoring and Debugging** Proxies can be used to monitor resources like databases for logging queries, execution time and result, helping others to enchance the performance.
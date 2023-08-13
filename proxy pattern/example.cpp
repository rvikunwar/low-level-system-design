
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Image {
    public:
        virtual void display() = 0;
};

// Image class defines an interface for both Image and ImageProxy class. It 
// declares a virtual method display(), which is responsible for displaying an image. 

class RealImage: public Image {
    private:
        string filename;

    public:
        RealImage(): filename(filename){
            loadImage();
        }

        void loadImage() {
            cout<<"Loading images . . ."<<endl;
            // this function loads a images from a remote server
        }

        void display() override {
            cout<<"Display image . . ."<<endl;
        }
};
// RealImage class represents an actual image. It implements the Image interface and provides
// the functionality of loading and displaying image. So, whenever RealImage object is created,
// an image will be loaded from the remote server with or without any its use.

class ImageProxy: public Image {
    private:
        shared_ptr<RealImage> realImage;
        string filename;

    public:
        ImageProxy(string filename): filename(filename){}

        void display() override {
            if(!realImage) {
                realImage = make_shared<RealImage> (filename);
            }
            realImage->display();
        }
};

// The ImageProxy acts as a proxy for images. It implements the Image interface. It maintain
// real image pointer and display function which first checks if the image is loaded or not. If not, it
// creates an instance of RealImage and loads the image using lazy loading and once the 
// realImage is loaded, it calls display() method on it.


int main() {
    ImageProxy px1("image1.png");
    ImageProxy px2("image2.png");
    cout<<"Displaying images . . ."<<endl;

    px1.display(); // displays and loads when called
    px2.display(); // same- only display when required

    return 0;
}

// The proxy pattern is employed here to control the creation and loading of the resource intensive
// object until they are actually needed for display. This can lead to better resource management and 
// improved performance in these scenarios where resource loading is time consuming and resource 
// intensive.
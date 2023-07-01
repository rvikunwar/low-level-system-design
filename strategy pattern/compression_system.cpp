#include <bits/stdc++.h>
using namespace std;


// Strategy interface
class CompressionStrategy {
    public:
        virtual void compressFile(const string& file) = 0;
};

class ZIPCompressionStrategy: public CompressionStrategy {
    public:
        void compressFile(const string& file) override {
            cout<<"Compression of file using ZIP"<<endl;
        }
};


class RARCompressionStrategy: public CompressionStrategy {
    public:
        void compressFile(const string &file) override {
            cout<<"Compression of file using RAR"<<endl;
        }
};

// Context strategy
class CompressionContext {
    private:
        CompressionStrategy* strategy;

    public:
        void setCompressionStrategy(CompressionStrategy* strategy) {
            this->strategy = strategy;
        } 

        void compressFile(const string& file) {
            strategy->compressFile(file);
        }
};


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
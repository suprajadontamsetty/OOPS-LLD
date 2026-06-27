#include<iostream>
#include<string>

using namespace std;

//Subject Interface
class IImage{
  public:
  virtual void display();
  virtual ~IImage()=default;
};

class RealImage:public IImage{
  string filename;
  public:
  RealImage(string file){
    this->filename=file;
    //HEAVY EXPENSIVE OPERATION DONE IN CONSTRUCTOR SO IMAGE CAN BE DISPLAYED INSTANTLY WHEN display() is called.
    cout << "[RealImage] Loading image from disk: " << filename << "\n";
  }

  void display() override {
     cout << "[RealImage] Displaying " << filename << "\n";
  }
};


//Proxy
class ImageProxy:public IImage{
   RealImage* realImage;
   string filename;

   public:
   ImageProxy(string file){
    this->filename=file;

    realImage=nullptr;
   }

   void display(){
    //Lazy initialization of RealImage
    if(!realImage){
        realImage=new RealImage(filename);
    }
    realImage->display();
   }
};

int main() {
    IImage* image1=new ImageProxy("sample.jpg");
    image1->display();
}
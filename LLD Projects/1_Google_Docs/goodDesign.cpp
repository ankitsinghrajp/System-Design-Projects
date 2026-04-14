#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class DocumentEditor{
    private:
       vector<string> documentElements;
       string renderedDocument;

    public:
      void addText(string text){
        documentElements.push_back(text);
      }

      void addImage(string imagePath){
        documentElements.push_back(imagePath);
      }

      // check the type at run time and render
      string renderDocument(){
          if(renderedDocument.empty()){
            string result;
            for(auto element: documentElements){
                if(element.size() > 4 && 
                (element.substr(element.size()-4) == ".jpg" || 
                 element.substr(element.size()-4) == ".png"
            )){

                result += "[Image: "+element+"]" + "\n";

            }
            else{
                result += element + "\n";
            }
            }

            renderedDocument = result;
            return renderedDocument;
          }
          else{
            return renderedDocument;
          }
      }

      void saveToFile(){
        ofstream file("document.txt");
        if(file.is_open()){
            file << renderDocument();
            file.close();
            cout<<"Document saved to document.txt"<<endl;
        }
        else{
            cout<<"Error: Can't open the file for write"<<endl;
        }
      }
};
int main(){
   DocumentEditor editor;
   editor.addText("This is boy Ankit Singh Rajput!");
   editor.addImage("ankits-profile.png");
   editor.addImage("cover-image.jpg");
   editor.addText("I am a scalable backend Engineer");
   editor.addText("I am a product Engineer");
   editor.saveToFile();

    return 0;
}
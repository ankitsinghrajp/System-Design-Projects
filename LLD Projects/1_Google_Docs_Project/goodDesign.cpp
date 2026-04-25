#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class DocumentElement{
   public:
      virtual string render() = 0;
};
class TextElement: public DocumentElement{
    private:
       string text;

    public: 
      TextElement(string text){
        this->text = text;
      }

      string render() override{
        return text;
      }
};

class ImageElement: public DocumentElement{
    private:
        string imagePath;

    public: 
      ImageElement(string imagePath){
          this->imagePath = imagePath;
      }

      string render() override{
        return "[Image: " + imagePath + "]";
      }
};

class NewLineElement: public DocumentElement{
    public:
    string render() override{
        return "\n";
    }
};

class TabsElement: public DocumentElement{
    public: 
      string render() override{
        return "\t";
      }
};

class Document{
    private:
      vector<DocumentElement*> documentElements;

    public:
      void addElement(DocumentElement* element){
               documentElements.push_back(element);
      }

      string render(){
        string result;
        for(auto element: documentElements){
            result += element->render();
        }
        return result;
      }
};

class Persistance{
    public:
    virtual void save(string data) = 0;
};

class FileStorage: public Persistance{
    public:
      void save(string data) override{
          ofstream file("document.txt");

          if(file.is_open()){
            file << data;
            file.close();
            cout<<"Document saved to document.txt file successfully!"<<endl;
          }
          else{
            cout<<"Error: Unable to open file for writing."<<endl;
          }
      }
};

class DBStorage: public Persistance{
    public:
      void save(string data) override{
        cout<<"The file saved to the DB Successfully!"<<endl;
      }
};

class DocumentEditor{
   Document* document;
   Persistance* storage;
   string renderedDocument;

   public:
    DocumentEditor(Document* document, Persistance* storage){
        this->document = document;
        this->storage = storage;
    }

    void addText(string text){
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath){
        document->addElement(new ImageElement(imagePath));
    }

    void addNewLine(){
        document->addElement(new NewLineElement());
    }

    void addTabsSpace(){
        document->addElement(new TabsElement());
    }

    string renderDocument(){
        if(renderedDocument.empty()){
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void saveDocument(){
        storage->save(renderDocument());
    }
};
int main(){

    Document* document = new Document();
    Persistance* persistance = new FileStorage();

    DocumentEditor* editor = new DocumentEditor(document,persistance);
    
    editor->addText("This is boy Ankit Singh Rajput from good design!");
    editor->addNewLine();
    editor->addText("The total electric flux through a closed surface it should be equal to the ratio qinside or epsilon not times the total charge enclosed by the closed surface!");
    editor->addNewLine();
    editor->addTabsSpace();
    editor->addText("This is the new text after tabs space!");
    editor->addNewLine();
    editor->addImage("myimage.png");
    editor->addNewLine();
    editor->addImage("yourimage.jpg");
    editor->addNewLine();
    editor->addImage("OursImage.jpeg");

    editor->saveDocument();
    
    return 0;
}
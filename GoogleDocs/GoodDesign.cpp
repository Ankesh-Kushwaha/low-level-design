#include<bits/stdc++.h>
using namespace std;

class DocumentElement{
   public:
     virtual string render() = 0;
};

class TextElement:public DocumentElement{
  string txt;
  public:
  TextElement(string txt){
    this->txt = txt;
  }

  string render()override{
    return txt;
  }
};

class ImageELement:public DocumentElement{
   string image;
   public:
   ImageELement(string img){
     this->image = img;
   }

   string render()override{
     return "[Image:" + image + "]";
   }
};

class newLine:public DocumentElement{
  public:

  string render() override{
    return "\n";
  }
};

class TabSpaceElement:public DocumentElement{
  public:
  string render()override{
    return "\t";
  }
};

class Persistance{
   public:
     virtual void save(string data) = 0;
};

class saveToFile:public Persistance{
  public:
  void save(string data){
    ofstream file("document.txt");
    if(file.is_open()){
      file << data;
      file.close();
      cout << "Document successfully saved to file document.txt" << endl;
    }
    else{
      cout << "ERROR :error while saving data to file" << endl;
    }
  }
};

class saveToDataBase:public Persistance{
  public:
  void save(string data){
    cout << "data is successfully saved in database" << endl;
  }
};

class Document{
  private:
    vector<DocumentElement *> document;
  
  public:
  void addElement(DocumentElement* ele){
    document.push_back(ele);
  }

  string render(){
    string result = "";
    for(auto doc:document){
      result += doc->render();
    }
    return result;
  }
};

class DocumentEditor{
  Document *doc;
  Persistance *storage;
  string renderElement;

  public:
  DocumentEditor(Document* doc,Persistance* storage){
    this->doc = doc;
    this->storage = storage;
  }

  void addText(string txt){
    doc->addElement(new TextElement(txt));
  }

  void addImage(string img){
    doc->addElement(new ImageELement(img));
  }

  void addNewLIne(){
    doc->addElement(new newLine());
  }

  void addTab(){
    doc->addElement(new TabSpaceElement());
  }

  string render(){
     if(renderElement.empty()){
       renderElement = doc->render();
     }
     return renderElement;
  }

  void save(){
    storage->save(render());
  }
};

int main(){
  Document *docs = new Document();
  Persistance *persistance = new saveToFile();
  DocumentEditor *editor = new DocumentEditor(docs, persistance);

  editor->addImage(".png");
  editor->addNewLIne();
  editor->addImage("https//:djhjdhjdhjdjdjjjd.jng");
  editor->addText("hello how are you");
  editor->addTab();
  editor->addNewLIne();
  editor->addText("tyeygysgsvbvxbxvxsjssjs dghdghdgd hhshss");

  cout << editor->render() << endl;
  editor->save();
  return 0;
}
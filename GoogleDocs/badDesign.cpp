#include<bits/stdc++.h>
using namespace std;

class DocumentEditor{
 private:
 vector<string> document;
 string renderElement;

 public:

 void addText(string txt){
   document.push_back(txt);
 }

 void addImage(string img){
   document.push_back(img);
 }

 string render(){
   if(renderElement.empty()){
     string result = "";
     for(auto doc:document){
          if(doc.size()>4 && (doc.substr(doc.size()-4)==".png"  || doc.substr(doc.size()-4)==".pdf")){
            result += "[ Image :" + doc + "]" + "\n";
          }
          else{
            result += doc+"\n";
          }
     }

     renderElement = result;
   }

   return renderElement;
 }

 void saveToFile(){
   ofstream file("document.txt");
   if(file.is_open()){
     file << render();
     file.close();
     cout << "Document saved to document.txt" << endl;
   }
   else{
     cout << "ERROR: unable to save document to file" << endl;
   }
 }
};

int main(){
  DocumentEditor editor;

  editor.addImage("https//ldlklkflkffm_jffff.png");
  editor.addText("hello how are you . and how are you doing");
  editor.addText("hi i am fine and doing well tell me about your self");
  editor.addImage("https//:hbdhdjdhj.pdf");

  cout << editor.render() << endl;
  editor.saveToFile();

  return 0;
}
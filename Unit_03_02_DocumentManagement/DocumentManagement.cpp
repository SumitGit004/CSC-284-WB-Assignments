#include <iostream>
#include <memory>
using namespace std;

//Simple Document class using smart pointers for memory management
class Document{
    private:
    string title;
    unique_ptr<string> content;
    
    public:
    //constructor
    Document(string title, unique_ptr<string> content){
        this->title = title;
        this->content = move(content);//transfers ownership

        cout << "Document \"" << title << "\" created.\n";
    } 
     //destructor
    ~Document() {
        cout << "Document \"" << title << "\" destroyed.\n";
        
    }
    //displays document title and content
    void show() {
        cout << "Title: " << title << endl
             << "Content:" << *content << endl;
    }
    // modifies the content of document
    void  edit(const string& newContent){
       *content = newContent;
    }

};
//helper function to dynamically create a document and return a unique_ptr to it
unique_ptr<Document> createDocument(const string& title, const string&) {
    return make_unique<Document>(title, make_unique<string>("Initial Content"));    
}
//helper function to dynamically create a document and return a shared_ptr to it.
shared_ptr<Document> createSharedDocument(const string& title, const string& content) {
    return make_shared<Document>(title, make_unique<string>(content));
}   


int main() {
        cout << "=== Unique_ptr demonstration ===\n";
    unique_ptr<Document> doc1 = createDocument("My Unique Doc", "Initial content");
    doc1->show();

    // Transfer ownership
    unique_ptr<Document> doc2 = move(doc1);
    if (!doc1) {
        cout << "doc1 no longer owns the document\n";
    }
    doc2->edit("Updated content");
    doc2->show();

    cout << "\n=== Shared_ptr demonstration ===\n";
    shared_ptr<Document> sharedDoc = createSharedDocument("Shared Doc", "Shared content");
    {
        shared_ptr<Document> viewer = sharedDoc;  // second owner
        viewer->show();
        viewer->edit("Edited by viewer");
    } // viewer goes out of scope, document still exists as shared_ptr sharedDoc still owns it so document SharedDoc is not destryoed.

    sharedDoc->show();
    cout << "End of main()\n";

    return 0;
}
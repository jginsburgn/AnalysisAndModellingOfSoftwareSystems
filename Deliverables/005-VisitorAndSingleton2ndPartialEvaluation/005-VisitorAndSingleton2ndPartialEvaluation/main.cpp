//
//  main.cpp
//  005-VisitorAndSingleton2ndPartialEvaluation
//
//  Created by Jonathan Ginsburg on 4/3/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

template <typename Element, typename Visitor>
class VisitableArray { //Singleton, proxy, visitable array abstraction

private:
    VisitableArray() = default;
    static VisitableArray * instance;
    
public:

    std::vector<Element *> elements;
    std::vector<Visitor *> visitors;

    static VisitableArray * getInstance() {
        if (instance == NULL) {
            instance = new VisitableArray();
        }
        return instance;
    }

    void executeVisits() {
        for (typename std::vector<Element *>::iterator element = elements.begin(); element != elements.end(); element++) {
            for (typename std::vector<Visitor *>::iterator visitor = visitors.begin(); visitor != visitors.end(); visitor++) {
                ((Element *)(* element))->accept((Visitor *)(* visitor));
            }
        }
    }
};

template <typename Element, typename Visitor>
VisitableArray<Element, Visitor> * VisitableArray<Element, Visitor>::instance = NULL;

class PlainText;
class RichText;
class ImageFile;

class AbstractPrinter { //Visitor
public:
    virtual void visit(PlainText * document) = 0;
    virtual void visit(RichText * document) = 0;
    virtual void visit(ImageFile * document) = 0;
};

class AbstractDocument { //Element
public:
    std::string contents;
    virtual void accept(AbstractPrinter * printer) = 0;
};

class PlainText : public AbstractDocument {
public:
    PlainText() {
        contents = "Plain text";
    }
    void accept(AbstractPrinter * printer) override {
        printer->visit(this);
    }
};

class RichText : public AbstractDocument {
public:
    RichText() {
        contents = "Rich text";
    }
    void accept(AbstractPrinter * printer) override {
        printer->visit(this);
    }
};

class ImageFile : public AbstractDocument {
public:
    ImageFile() {
        contents = "⚛";
    }
    void accept(AbstractPrinter * printer) override {
        printer->visit(this);
    }
};

class LaserPrinter : public AbstractPrinter {
public:
    void visit(PlainText * document) override {
        std::cout << "Laser printer (plain text): " << document->contents << std::endl;
    }

    void visit(RichText * document) override {
        std::cout << "Laser printer (rich text): " << document->contents << std::endl;
    }

    void visit(ImageFile * document) override {
        std::cout << "Laser printer (image): " << document->contents << std::endl;
    }
};

class InjectionPrinter : public AbstractPrinter {
public:
    void visit(PlainText * document) override {
        std::cout << "Injection printer (plain text): " << document->contents << std::endl;
    }

    void visit(RichText * document) override {
        std::cout << "Injection printer (rich text): " << document->contents << std::endl;
    }

    void visit(ImageFile * document) override {
        std::cout << "Injection printer (image): " << document->contents << std::endl;
    }
};

class PDFPrinter : public AbstractPrinter {
public:
    void visit(PlainText * document) override {
        std::cout << "PDF printer (plain text): " << document->contents << std::endl;
    }

    void visit(RichText * document) override {
        std::cout << "PDF printer (rich text): " << document->contents << std::endl;
    }

    void visit(ImageFile * document) override {
        std::cout << "PDF printer (image): " << document->contents << std::endl;
    }
};

class PostscriptPrinter : public AbstractPrinter {
public:
    void visit(PlainText * document) override {
        std::cout << "Postscript printer (plain text): " << document->contents << std::endl;
    }

    void visit(RichText * document) override {
        std::cout << "Postscript printer (rich text): " << document->contents << std::endl;
    }

    void visit(ImageFile * document) override {
        std::cout << "Postscript printer (image): " << document->contents << std::endl;
    }
};


int main(int argc, const char * argv[]) {

    //Get visitable array singleton
    VisitableArray<AbstractDocument, AbstractPrinter> * va = VisitableArray<AbstractDocument, AbstractPrinter>::getInstance();

    //Add documents (elements) to the Visitable Array
    PlainText pt;
    RichText rt;
    ImageFile imgFile;
    va->elements.push_back(&pt);
    va->elements.push_back(&rt);
    va->elements.push_back(&imgFile);

    //Add printers (visitors) to the Visitable Array
    LaserPrinter lp;
    InjectionPrinter ip;
    PDFPrinter pdfp;
    PostscriptPrinter pp;
    va->visitors.push_back(&lp);
    va->visitors.push_back(&ip);
    va->visitors.push_back(&pdfp);
    va->visitors.push_back(&pp);

    //Dispatch visitors
    va->executeVisits();

    return 0;
}

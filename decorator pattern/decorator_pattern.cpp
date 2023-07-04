// decorator_pattern

# include<bits/stdc++.h>
using namespace std;

// interface
class TextComponent{
	public:
		virtual string getText() = 0;
};

// concrete class
class Text: public TextComponent {
	private:
		string text;

	public:
		Text(string text){
			this->text = text;
		}

		string getText() override {
			return text;
		}
};


//decorator 
class TextDecorator: public TextComponent {
	protected:
		TextComponent *textcomponent;
	public:
		TextDecorator(TextComponent *textcomponent){
			this->textcomponent = textcomponent;
		}

		string getText() override {
			return textcomponent->getText();
		}
};	


class BoldTextDecorator: public TextDecorator {
	public:
		BoldTextDecorator(TextComponent* text): TextDecorator(text){};

		string getText() override {
			return "<b>" + textcomponent->getText() + "</b>";
		}

};


class ItalicTextDecorator: public TextDecorator {
	public:
		ItalicTextDecorator(TextComponent* text): TextDecorator(text){};

		string getText() override {
			return "<i>" + textcomponent->getText() + "</i>";
		}
};


int main(){
	TextComponent *text = new Text("Hello world!!");
	text = new BoldTextDecorator(text);
	text = new ItalicTextDecorator(text);

	cout<<"Updated text: " + text->getText()<<endl; 
	return 0;
};
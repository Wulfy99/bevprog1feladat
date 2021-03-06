#include "std_lib_facilities.h"

class Token {
public:
    char kind;        // Milyen token ez pontosan
    double value;     // A number nevű változóhoz
    Token(char ch)    // Csinál egy tokent a char változóból
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // A char-ból csonál egy double tokent
        :kind(ch), value(val) { }
};


class Token_stream {
public: 
    Token_stream();   // Csinál egy Token_stream ami az inputból jön (cin)
    Token get();      //Kap egy tokent(get() dekralálva van vhon )
    void putback(Token t);    // put a Token back
private:
    bool full;        // Egy bool arra a kérédsre hogy van-e most tokenünk
    Token buffer;     // Itt használjuka buffer Tokent és visszarakjuk a  putback() paranccsal
};




Token_stream::Token_stream()
:full(false), buffer(0)    // Nincs Tokenünk
{}

// A putback() bekehelyezi ide a tokent a Token_stream's buffer-be
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // Lemásoljuk a t buffert
    full = true;      // Mostmár van valami a bufferben
}



Token Token_stream::get()
{
    if (full) {       // Ellenőrzés hogy van e token (biztonsági lépés)
        // Töröljük a tokent a bufferből
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;    
    switch (ch) {
    case '=':    // a kiíráshoz
    case 'x':    // a leállításoz
    case 'X':    // ezzel a nagybetűs kilépést is eléhetővé tesszük
    case '(': case ')': case '+': case '-': case '*': case '/': case '%':
        return Token(ch);        //
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         
            double val;
            cin >> val;              //Beolvassuk a karakter láncot
            return Token('8',val);   
    default:
        error("Bad token");
    }
}


Token_stream ts;        



double expression();    

// A paraméterek és számok használata
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // Kezeljük a zárójeleket
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case '8':            
        return t.value;   
    default:
        error("primary expected");
    }
}



//A magasab rendű műveletek vizsgálata és elvégzése
double term()
{
    double left = primary();
    Token t = ts.get();        // A következő Token streamre megyünk át


    while(true) {
        switch (t.kind) {
        case '*':
            {
                left *= primary();
                t = ts.get();
                break;
            }
        case '/':
            {    
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        case '%':
            {    
                int d = primary();
                int l = left;
                if (d == 0) error("divide by zero");
                left = l%d; 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);     
            return left;
        }
    }
}


// Az összedás és kivonással való számolás
double expression()
{
    double left = term();      
    Token t = ts.get();        

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    
            t = ts.get();
            break;
        case '-':
            left += term();    
            t = ts.get();
            break;
        default: 
            ts.putback(t);     
            return left;      
        }
    }
}

int main()
try
{ 
    cout << "Welcome to our simple calculator."<<endl;
    cout << "Please enter expressions using floating point numbers."<<endl;
    cout << "Available operators are: '+','-','*','/', and '%'. Enter X to quit." << endl;
    cout << "Enter '=' when you want to solve your input." << endl;
    double val;
    while (cin) {
        Token t = ts.get();

        if (t.kind == 'x') break; // 'q' a kilépésért
        if (t.kind == '=')        // ';' az azonnali kiírásért
            cout << "=" << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
	keep_window_open();
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
	keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
	keep_window_open();
    return 2;
}
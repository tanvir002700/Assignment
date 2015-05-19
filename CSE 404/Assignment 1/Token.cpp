#include<bits/stdc++.h>
using namespace std;
template <class T> void print_vector(T v)
{
    int sz=v.size()-1;
    for(int i=0;i<=sz;i++)cout<<v[i]<<" \n"[i==sz];
}
class Token
{
    private:
        map<string,bool>token;
        map<char,bool>operators;
        string code;
        set<string>Operators,keywords,Identifiers,strings,constants;
        set<string>specialSymbol;
        void init();
        void process();
        bool isKeyWord(string str);
        bool isOperator(char str);
        bool isSpecialSymbol(char str);
    public:
        Token(string file_name);
        vector<string>getKeywords();
        vector<string>getIdentifires();
        vector<string>getStrings();
        vector<string>getConstants();
        vector<string>getOperators();
        vector<string>getSpecialSymbol();
};
void Token::init()
{
    FILE *fp=fopen("keyword.txt","r");
    while(!feof(fp))
    {
        char tk[100];
        fscanf(fp,"%s",tk);
        token[tk]=true;
    }
    fclose(fp);
    fp=fopen("operator.txt","r");
    while(!feof(fp))
    {
        char c[3];
        fscanf(fp,"%s",c);
        operators[c[0]]=true;
    }
    fclose(fp);
}
bool Token::isKeyWord(string str)
{
    return token.find(str)!=token.end();
}
bool Token::isOperator(char str)
{
    return operators.find(str)!=operators.end() and str!=' ';
}
void Token::process()
{
    for(int i=0; i<code.size(); i++)
    {
        string str="";
        if(isdigit(code[i]))
        {
            while(isdigit(code[i]))
            {
                str+=code[i];
                i++;
            }
            constants.insert(str);
            i--;
        }
        else if(code[i]=='\"')
        {
            str+='\"';
            i++;
            while(code[i]!='\"')
            {
                str+=code[i];
                i++;
            }
            str+='\"';
            strings.insert(str);
        }
        else if(isalpha(code[i]) || code[i]=='_')
        {
            while(isalpha(code[i])||isdigit(code[i])|| code[i]=='_')
            {
                str+=code[i];
                i++;
            }
            if(isKeyWord(str))keywords.insert(str);
            else Identifiers.insert(str);
            i--;
        }
        else
        {
            if(isOperator(code[i]))
            {
                while(isOperator(code[i]))
                {
                    str+=code[i];
                    i++;
                }
                Operators.insert(str);
                i--;
            }
            else if(code[i]!=' ' and code[i]!='\n')
            {
                str="";
                str+=code[i];
                specialSymbol.insert(str);
            }
        }
    }
}
Token::Token(string filename)
{
    init();
    FILE *fp=fopen(filename.c_str(),"r");
    code="";
    while(!feof(fp))
    {
        char c;
        fscanf(fp,"%c",&c);
        code+=c;
    }
    fclose(fp);
    process();
}
vector<string>Token::getKeywords()
{
    vector<string>ret;
    for(auto x:keywords)ret.push_back(x);
    return ret;
}
vector<string>Token::getIdentifires()
{
    vector<string>ret;
    for(auto x:Identifiers)ret.push_back(x);
    return ret;
}
vector<string>Token::getConstants()
{
    vector<string>ret;
    for(auto x:constants)ret.push_back(x);
    return ret;
}
vector<string>Token::getStrings()
{
    vector<string>ret;
    for(auto x:strings)ret.push_back(x);
    return ret;
}
vector<string>Token::getOperators()
{
    vector<string>ret;
    for(auto x:Operators)ret.push_back(x);
    return ret;
}
vector<string>Token::getSpecialSymbol()
{
    vector<string>ret;
    for(auto x:specialSymbol)ret.push_back(x);
    return ret;
}
int main()
{
    Token t("input.cpp");
    printf("Keywords (%d): ",t.getKeywords().size());
    print_vector(t.getKeywords());
    printf("Identifiers (%d): ",t.getIdentifires().size());
    print_vector(t.getIdentifires());
    printf("Constants (%d): ",t.getConstants().size());
    print_vector(t.getConstants());
    printf("Strings (%d): ",t.getStrings().size());
    print_vector(t.getStrings());
    printf("Special symbols (%d): ",t.getSpecialSymbol().size());
    print_vector(t.getSpecialSymbol());
    printf("Operators (%d): ",t.getOperators().size());
    print_vector(t.getOperators());
    return 0;
}

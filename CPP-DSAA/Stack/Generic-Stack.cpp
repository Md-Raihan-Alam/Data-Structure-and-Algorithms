#include<iostream>
#include<string>
using namespace std;
int pre(char x)
{
    if(x=='+' || x=='-')
    {
        return 1;
    }else if(x=='*' || x=='/')
    {
        return 2;
    }else if(x=='^')
    {
        return 3;
    }
    return 0;
}
int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    return 1;
}
template<class DT> class Node{
    public:
    DT data;
    Node *next;
};
template<class DT2> class Stack{
    private:
    Node<DT2> *top;
    public:
    Stack(){
        top=NULL;
    }
    DT2 Top()
    {
        return top->data;
    }
    void Push(DT2 x)
    {
        Node<DT2> *t=new Node<DT2>;
        if(t==NULL)
        {
            cout<<"Stack is full"<<endl;
            return ;
        }
        t->data=x;
        t->next=top;
        top=t;
    }
    DT2 Pop()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty"<<endl;
            
        }else{
            DT2 x=-1;
            x=top->data;
            Node<DT2> *t=top;
            top=top->next;
            delete t;
            return x;
        }
        
    }
    void Display()
    {
        Node<DT2> *p=top;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    void Peek(int index)
    {
        Node<DT2> *p=top;
        int count=1;
        while(p!=NULL && count<index)
        {
            p=p->next;
            count++;
        }
        if(p==NULL || index<=0)
        {
            cout<<"Index "<<index<<" is out of bound"<<endl;
            return ;
        }
        cout<<p->data<<endl;
    }
    int isBalanced(string exp)
    {
        for(int i=0;exp[i]!='\0';i++)
        {
            if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            {
                Push(exp[i]);
            }else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
            {
                if(top==NULL)
                {
                    return 0;
                }else if(exp[i]==')' && top->data!='(')
                {
                    return 0;
                }else if(exp[i]=='}' && top->data!='{')
                {
                    return 0;
                }else if(exp[i]==']' && top->data!='[')
                {
                    return 0;
                }
                Pop();
            }
        }
        if(top==NULL)
        {
            return 1;
        }
        return 0;
    }
    string InToPost(string infix)
    {
        string postfix;
        int len = infix.size();
        int i = 0;

        while (i < len)
        {
            if (isOperand(infix[i]))
            {
                postfix.push_back(infix[i++]);
            }
            else if (infix[i] == '(')
            {
                Push(infix[i++]);
            }
            else if (infix[i] == ')')
            {
                while (top != NULL && top->data != '(')
                {
                    postfix.push_back(Pop());
                }
                if (top != NULL && top->data == '(')
                {
                    Pop(); 
                    i++;
                }
                else
                {
                    // Mismatched parenthesis
                    cout << "Mismatched parenthesis" << endl;
                    return ""; 
                }
            }
            else
            {
                while (top != NULL && pre(infix[i]) <= pre(top->data))
                {
                    postfix.push_back(Pop());
                }
                Push(infix[i++]);
            }
        }

        while (top != NULL)
        {
            if (top->data == '(' || top->data == ')')
            {

                cout << "Mismatched parenthesis" << endl;
                return ""; 
            }
            postfix.push_back(Pop());
        }

        return postfix;
    }
    int Eval(string postFix)
    {
        int x1,x2,r;
        for(int i=0;i<postFix.size();i++)
        {
            if(isOperand(postFix[i]))
            {
                Push(postFix[i]-'0');
            }else{
                x2=Pop();
                x1=Pop();
                switch (postFix[i])
                {
                case '+':
                    r=x1+x2;
                    break;
                case '-':
                    r=x1-x2;
                    break;
                case '*':
                    r=x1*x2;
                    break;
                case '/':
                    r=x1/x2;
                    break;
                case '^':
                    r = 1;
                    for (int j = 0; j < x2; j++)
                    {
                        r *= x1;
                    }
                    break;
                default:
                    cout<<"Invalid"<<endl;
                    return 0;
                }
                Push(r);
            }
        }
        return top->data;
    }
};
int main()
{
    Stack<char> st;
    string exp="{([a+b]*[c-d])/e}";
    string infix="a+b*c";
    string postfix="234*+82/-";
    // st.Push('a');
    // st.Push('b');
    // st.Push('c');
    // cout<<st.Top()<<endl;
    // st.Display();
    // cout<<st.Pop()<<endl;
    // st.Display();
    // st.Peek(2);
    // cout<<st.isBalanced(exp)<<endl;
    // cout<<st.InToPost(infix)<<endl;
    cout<<st.Eval(postfix)<<endl;
    return 0;
}
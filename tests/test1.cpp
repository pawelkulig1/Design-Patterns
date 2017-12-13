#include <iostream>

using namespace std;

class Color
{
  public:
    virtual void accept(class Visitor*) = 0;
};

class Red: public Color
{
  public:
     /*virtual*/void accept(Visitor*);
    void eye()
    {
        cout << "Red::eye\n";
    }
};
class Blu: public Color
{
  public:
     /*virtual*/void accept(Visitor*);
    void sky()
    {
        cout << "Blu::sky\n";
    }
};

class Green: public Color
{
public:
    void accept(Visitor*);
     void grass()
     {
         cout<<"Green::grass";
         cout<<"test"<<endl;
     }
};

class Visitor
{
  public:
    virtual void visit(Red*) = 0;
    virtual void visit(Blu*) = 0;
    virtual void visit(Green*) = 0;
};

class CountVisitor: public Visitor
{
  public:
    CountVisitor()
    {
        m_num_red = m_num_blu = 0;
        m_num_green = 0;
    }
     /*virtual*/void visit(Red*)
    {
        ++m_num_red;
    }
     /*virtual*/void visit(Blu*)
    {
        ++m_num_blu;
    }
    void visit(Green *)
    {
        ++m_num_green;
    }

    void report_num()
    {
        cout << "Reds " << m_num_red << ", Blus " << m_num_blu << '\n';
        cout<<"Greens: "<< m_num_green<<endl;
    }
  private:
    int m_num_red, m_num_blu, m_num_green;
};

class CallVisitor: public Visitor
{
  public:
     /*virtual*/void visit(Red *r)
    {
        r->eye();
    }
     /*virtual*/void visit(Blu *b)
    {
        b->sky();
    }

    void visit(Green *g)
    {
        g->grass();
    }
};

void Red::accept(Visitor *v)
{
  v->visit(this);
}

void Blu::accept(Visitor *v)
{
  v->visit(this);
}

void Green::accept(Visitor *v)
{
    v->visit(this);
}

int main()
{
  Color *set[] =
  {
    new Red, new Blu, new Blu, new Red, new Red, new Green, new Green, 0
  };
  CountVisitor count_operation;
  CallVisitor call_operation;
  for (int i = 0; set[i]; i++)
  {
    set[i]->accept(&count_operation);
    set[i]->accept(&call_operation);
  }
  count_operation.report_num();
}

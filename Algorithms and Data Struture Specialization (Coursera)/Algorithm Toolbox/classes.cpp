#include <iostream>

using namespace std;

class math{
    protected:
        int x,y;
    public:
        void getX(int a){
            x=a;
        }
        void getY(int a){
            y=a;
        }
        virtual int ad()=0;
};
class addition :public math{
    public:
    int ad(){
        cout << "addition completed" << endl;
        return x+y;
    }
};
class subtraction :public math{
    public:
    int ad(){
        cout << "subtraction completed" << endl;
        return x-y;
    }
};

int main()
{
    addition d;
    subtraction s;
    math *m;
    m=&d;
    m->getX(5);m->getY(2);m->ad();
    return 0;
}

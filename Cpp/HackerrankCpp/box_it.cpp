#include <iostream>

class Box{
    private:
        long long l, b, h;
    public:
        Box(): l {0}, b{0}, h{0} {}
        Box(int le, int br, int he)
            : l{le}, b {br}, h {he}
        {};
        // Copy constructor
        Box(Box &B):
            l{B.l},
            b{B.b},
            h{B.h}
        {};

        int getLength() { return l; }
        int getBreadth() { return b; }
        int getHeight() { return h; }

        bool operator<(const Box &B){
            if ((this->l < B.l)
                    || (this->b < B.b && this->l == B.l)
                    || (this->h < B.h && this->b == B.b && this->l == B.l))
                return true;
            return false;
        }

        long long CalculateVolume() {
            return (l * b * h);
        }

        friend std::ostream& operator<<(std::ostream &out, const Box& B);
};

std::ostream& operator<< (std::ostream& out, const Box& B){
    out << B.l << " " << B.b << " " << B.h;
    return out;
}

void check2()
{
    int n;
    std::cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        std::cin>>type;
        if(type ==1)
        {
            std::cout<<temp<<std::endl;
        }
        if(type == 2)
        {
            int l,b,h;
            std::cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            std::cout<<temp<<std::endl;
        }
        if(type==3)
        {
            int l,b,h;
            std::cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                std::cout<<"Lesser\n";
            }
            else
            {
                std::cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            std::cout<<temp.CalculateVolume()<<std::endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            std::cout<<NewBox<<std::endl;
        }

    }
}

int main()
{
    check2();
}

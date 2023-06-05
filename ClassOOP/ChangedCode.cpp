//
//  main.cpp
//  q20
//
//  Created by brian on 10/5/22.
//
#include <iostream>
#include <cmath>
using namespace std;

class Timer
{
    protected:
        int setting;
        int current;
    public:
        Timer(int s)
        {
            setting = s;
            current = s;
        }
        virtual void OneTick()
        {
            current--;
        }

        virtual bool Done() const
        {
            return (current == 0);
        }

        void Reset()
        {
            current = setting;
        }

        void Go()
        {
            while (this->Done() == false)
            {
                cout << current << "*";
                this->OneTick();
            }
            cout << "ding!\n";
        }
};

class UpwardCounter : public Timer
{
    public:
        UpwardCounter(int s) : Timer(s)
        {
            current = 0;
        }
        virtual void OneTick()
        {
            current++;
        }
        virtual bool Done() const
        {
            return (current >= setting);
        }
        void Reset()
        {
            current = 0;
        }
};
//current function
class MultCounter : public UpwardCounter
{
    protected:
        int mult;
        int count;
    public:
        MultCounter(int s, int m) : UpwardCounter(s)
        {
            mult = m;
            current = 1;
            count = 1;
        }
        virtual void OneTick()
        {
            current = count++ * mult; //can be represended by the funtion f(current) = current ^ x
        }
        void Reset()
        {
            current = 1;
            count = 1;
        }
};
//function inherients from MultiCounter class
//from here the function uses uses 2 as a base and puts it to an exponential power
//the constructor only accepts 1 argument about the size of the program
class ExpoCounter : public MultCounter
{
protected:
    int base;
public:
    ExpoCounter(int s, int b) : MultCounter(s, 0)
    {
        current = 1;
        base = b;
    }
    virtual void OneTick()
    {
        current = current * base;
    }
    void Reset()
    {
        base = 2;
        current = 1;
    }
    
};

int main()
{
    
    //shows output of different classes that inherit from 'Timer' class
    cout << "Part 1: testing Timer\n";
    Timer timerA(4);
    timerA.Go();    //runs timmer
    cout << "\n";
    cin.get();
    
    cout << "Part 2: testing UpwardCounter\n";
    UpwardCounter upA(5);
    upA.Go();   //runs upwardcounter
    cout << "\n";
    cin.get();
     
    
    cout << "Part 3: testing MultCounter\n";
    MultCounter multC(8, 2);
    multC.Go();   //runs multcounter
    cout << "Testing it again:\n";
    MultCounter multD(100, 3);
    multD.Go();    //runs multcounter
    cout << "\n";
    cin.get();
    
    
    cout << "Part 4: testing Timer Reset()\n";
    timerA.Reset();
    timerA.Go();    //runs timer
    cout << "\n";
    cin.get();
    
    cout << "Part 5: testing UpwardCounter Reset()\n";
    upA.Reset();
    upA.Go();    //runs upwardcounter
    cout << "\n";
    cin.get();
    
    cout << "Part 6: testing MultCounter Reset()\n";
    multD.Reset();
    multD.Go();    //runs multicounter
    cout << "\n";
    
    cout << "Part 7: testing ExpoCounter\n";
    ExpoCounter ec1(100, 2);
    ec1.Go();    //runs expocounter
    cout << "Testing it again:\n";
    ExpoCounter ec2(1000, 4);
    ec2.Go();    //runs expocounter
    cout << "\n";
    cin.get();
    
    cout << "Part 8: testing ExpoCounter Reset()\n";
    ec1.Reset();
    ec1.Go();     //runs expocounter
    cout << "\n";
    
    return 0;
}




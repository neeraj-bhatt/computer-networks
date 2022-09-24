#include <iostream>
using namespace std;

class ParityCheck
{
    string msg;
    int lngth;
    public:
    string sender();
    void receiver(string b);
    string evenParity(string c);
};

string ParityCheck :: sender()
{
    cout << "Enter the message bits" << endl;
    cin >> msg;
    string nmsg = msg + evenParity(msg);
    cout << "Sent Bits (including paritybit) : " << nmsg << endl;
    return nmsg;
}

string ParityCheck :: evenParity(string c)
{
    lngth = msg.length();
    int count = 0;
    for(int i=0; i<lngth; i++)
    {
        if(c[i] == '1')
            count += 1;
    }
    if(count%2 == 0)
        return "0";
    else 
        return "1";
}

void ParityCheck :: receiver(string b)
{
    cout << "Received Bits : " << b << endl;
    int i = b.length();
    string chk = evenParity(b);
    if(b[i-1] == chk[0])
        cout << "Bits Received without any errors :)" << endl;
    else   
        cout << "There is some error in Received bits :(" << endl;
}

int main()
{
    ParityCheck obj;
    string a = obj.sender();
    obj.receiver(a);
    return 0;
}
// Testing code
// 
// isEven.cpp : 
// ODD check with bit calculation
// Circle buffer struct with methods

#include <iostream>
#define BUF_SIZE (5)

using namespace std;

bool isEven(int i) {
    return !(i & 0b0000'0001);
}

class circleBuffer {
public:
    circleBuffer() { wIndex= 0; rIndex = 0; length = 0;  }
    
    void putToBuffer(int);
    int GetFromBuffer();
    
    bool isBufferEmpty() { return length == 0; };
    int getBufferSize() { return length; };
    
    void printBuffer(); // for testing
    
private:
    int buffer[BUF_SIZE]; // catacity
    int wIndex, // where put new el
        rIndex, // which el first for getting
        length; // size of buf data
};

void circleBuffer::printBuffer() {
    if (length == 0) {
        std::cout << "Buffer is empty\n";
        return;
    }
    cout << "\n print Buffer : ";
    for (int i = 0; i < length; i++)
        cout << " [" << (rIndex + i) % BUF_SIZE << "] =" << buffer[(rIndex + i) % BUF_SIZE];
    cout << "\n";
};

// put in any case, even if the buffer is full (re-recording first el)
void circleBuffer::putToBuffer(int i) {
    buffer[wIndex] = i;
    wIndex = (wIndex + 1) % BUF_SIZE;
    if (length == BUF_SIZE) {
        rIndex = (rIndex + 1) % BUF_SIZE;
    }
    else length++;
    //        cout << "wIndex = " << wIndex << " rIndex = " << rIndex << " length= " << length << endl;
};

// need to catch try or other arch if try get from empty buffer
int circleBuffer::GetFromBuffer() {
    if (length > 0) {
        int res = buffer[rIndex];
        rIndex = (rIndex + 1) % BUF_SIZE;
        length--;
        cout << "wIndex = " << wIndex << " rIndex = " << rIndex << " length= " << length << endl;
        return res;
    }
    else return -1; // need to catch try or other arch
};


int main()
{
    cout << "Hello \n";
  

//buffer testing
    circleBuffer CB;
    CB.putToBuffer(1);
    CB.putToBuffer(2);
    CB.putToBuffer(3);
    CB.putToBuffer(4);
    CB.putToBuffer(5);
    CB.printBuffer();

    cout << "CB.GetFromBuffer() = " << CB.GetFromBuffer() << endl;
    CB.putToBuffer(6);
    CB.putToBuffer(7);
    CB.printBuffer();

    cout << "CB.GetFromBuffer() = " << CB.GetFromBuffer() << endl;
    cout << "CB.GetFromBuffer() = " << CB.GetFromBuffer() << endl;
    cout << "CB.GetFromBuffer() = " << CB.GetFromBuffer() << endl;
    cout << "CB.GetFromBuffer() = " << CB.GetFromBuffer() << endl;
    
    CB.printBuffer();

// ODD testing (111 - stop testing)
    int i;
    do {
        std::cout << "Enter number\n";
        cin >> i;
        if (isEven(i)) std::cout << " I = " << i << " - its true\n";
        else std::cout << " I = " << i << " - its odd\n";
    } while (i!= 111);

    std::cout << "\nEnd\n";
}


#include <iostream>
using namespace std;

int number;
void pattern(int stars, int spaces){
    

    if (stars==1) {
        for(int s = 0; s < spaces; s++){
            cout << " ";
        }
        cout << "*";
        cout << endl;
        return;
    }
    

    pattern(stars/2, spaces);
    
    for(int s = 0; s < spaces; s++){
        cout << " ";
    }
    
    for(int s = 0; s < stars; s++){
        cout << "*";
    }
    
    cout << endl;

    pattern(stars/2, spaces+(stars/2));
}
int main() {
    
    cout << "Enter a integer \n";
    cin >> number;
    cout << endl;
    cout << endl;
    pattern(number, 0);
    return 0;
}

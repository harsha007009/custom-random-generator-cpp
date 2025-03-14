#include<iostream>
using namespace std;
#include <stdexcept>  
/*X_{n+1} = (a*X_n+c)%m
where:
X_n = Current number (also called the seed).
a = Multiplier (a constant that influences randomness).
c = Increment (a constant that adds variation).
m = Modulus (keeps numbers within a range).
X_{n+1} = Next random number in the sequence.
*/
class myRandom{
    private:
    unsigned long seed;
    const unsigned long a = 1664525;
    const unsigned long c = 1013904223;
    const unsigned long long m = 4294967296;
    public:
    myRandom(unsigned long s){
        seed = s;
    }
    unsigned long next(){
        seed = (a*seed+c)%m;
        return seed;
    }
    int nextRandom(int min, int max) {
        if (min > max) {
            throw logic_error("Min value cannot be greater than Max value. Please enter valid values.");
        }
        return (next() % (max - min + 1)) + min;
    }

    int nextRandom() {
        return next();
    }
};
int main(){
    try{
    unsigned long userSeed;
    cout<<"Enter a seed value: ";
    cin>>userSeed;
    if(cin.fail()){
        throw runtime_error("Invalid input.Please enter a numeric seed.");
    }
    myRandom rand(userSeed);
    cout<<"Generated random number::"<<rand.nextRandom()<<endl;
    char choice;
    cout<<"Do you want to enter a min and max range? (y/n): ";
    cin >>choice;
    if(choice == 'y' || choice == 'Y'){
        while(choice == 'y' || choice == 'Y'){
        int min,max;
        cout<<"Enter min value: ";
        cin >> min;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a numeric value.\n";
            break;
        }
        cout<<"Enter max value: ";
        cin >> max;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a numeric value.\n";
            break;
        }
        try{
            cout << "Random number in rangwe [" << min << ", " << max << "]: " 
                         << rand.nextRandom(min, max) << endl;
        }
        catch(const logic_error& e){
            cout<<"Error"<<e.what()<<"Try again."<<endl;
        }
    cout << "Do you want to generate another random number in the range? (y/n): ";
    cin >> choice;
    }
}

}
catch(const invalid_argument &e){
    cerr<<"Error: "<<e.what()<<endl;
}
 catch (const logic_error& e) {
    cerr << "Logic Error: " << e.what() << endl;
} catch (const runtime_error& e) {
    cerr << "Runtime Error: " << e.what() << endl;
} catch (...) {
    cerr << "An unknown error occurred." << endl;
}
return 0;

}


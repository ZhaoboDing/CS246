using namespace std;

int foo(int &x, const int& y){
    return x + y;
}

int main(){
    int a = 42;
    foo(a,a);   // Valid
    foo(a,43)   // Valid: Pass by const reference allows this.
    foo(43,a);  // Invalid, what does it mean to change a literal?
    foo(43,43); // As above
}

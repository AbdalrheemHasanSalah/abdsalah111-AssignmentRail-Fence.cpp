// AssignmentRail Fence.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>


using namespace std;
char** Encryption(string str, int depth, int string_length);
void decryption(char** matrix, int depth, int string_length);
int main()
{    

	string str;
    cout << "input plaintext: ";
    getline(cin, str);
    
    int depth=0;
    while (depth == 0) {
        cout << "input depth: ";
        cin >> depth;
    }
    //to get the length of string
    const int  string_length = str.length();
    char** matrix=Encryption(str,depth,string_length);
   
    decryption(matrix, depth, string_length);
    return 0;
}

char** Encryption(string str, int depth,int string_length) {
   
    

    // Use dynamic memory allocation 
    char* arry_char = new char[string_length + 1];

    // copying the contents of the string to
      // char array
    strcpy(arry_char, str.c_str());
   
   
    cout << endl;
    //Dynamic Allocation of the 2D Matrix
    char** matrix = new char* [depth];

    for (int row = 0;row < depth;row++) {

        matrix[row] = new char[string_length];
        for (int col = 0;col < string_length;col++) {
            //fill it with null value
            matrix[row][col] = '\0';
        }

    }

    int row = 0;
    //doing reil fence cipher(zigzag)
    for (int i = 0;i < string_length;i++) {

      
        if (row == depth) { row = 0; }
        matrix[row][i] = arry_char[i];
        row++;
    }
    
    //to print the matrix after fill it with reil fence 
    for (int i = 0;i < depth;i++) {


        for (int j = 0;j < string_length;j++) {
            if (matrix[i][j] != '\0')
                cout << matrix[i][j];
        }

    }
    //delete arra char
    delete[]arry_char;
    return matrix;
   
    
}


void decryption(char **matrix, int depth,int string_length)
{

    // Use dynamic memory allocation 
    char* arry_char = new char[string_length + 1];

    cout << endl;
   

    int row = 0;
    //doing reil fence decryption(zigzag)
    for (int i = 0;i < string_length;i++) {


        if (row == depth) { row = 0; }
        arry_char[i]=matrix[row][i];
        row++;
    }

    //to print the matrix after decryption it with reil fence 
    for (int i = 0;i < string_length;i++) {
        cout<<arry_char[i];
    }
    //delete row matrix
    for (int i = 0; i < depth; i++) {
        delete[] matrix[i];
    }
    //delete matrix 
    delete[] matrix;
  
  
}

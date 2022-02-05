//Number Conversion project prototype.
//Authors: Angelo Ediriweera, Brian Carbonneau, Jonathan Ordiano, Roshan Indika Arachchige.
//date: 11/16/2020

#include <iostream>
#include <string.h>
#include <string>
#include <cmath>
using namespace std;

///TO DECIMAL FUNCTION.~Angelo.
// To return value of a char. For example, 2 is 
// returned for '2'.  10 is returned for 'A', 11 
// for 'B' ~ function used for the conversion below
int val(char c) 
{ 
    if (c >= '0' && c <= '9') 
        return (int)c - '0'; 
    else
        return (int)c - 'A' + 10; 
} 
///TO DECIMAL FUNCTION.~Angelo.  
// Function to convert a number from given base 'b' 
// to decimal 

int toDeci(string str, int base) 
{ 
    int len = str.length(); 
    int power = 1; // Initialize power of base 
    int num = 0;  // Initialize result 
    int i; 
  
    // Decimal equivalent is str[len-1]*1 + 
    // str[len-2]*base + str[len-3]*(base^2) + ... 
    for (i = len - 1; i >= 0; i--) 
    { 
        // A digit in input number must be 
        // less than number's base 
        if (val(str[i]) >= base) 
        { 
           cout << "Invalid Number"; 
           return -1; 
        } 
  
        num += val(str[i]) * power; 
        power = power * base; 
    } 
  
    return num; 
} 


// To return char for a value. For example '2' 
// is returned for 2. 'A' is returned for 10. 'B' 
// for 11 ~ Roshan 
char reVal(int num) 
{ 
    if (num >= 0 && num <= 9) 
        return (char)(num + '0'); 
    else
        return (char)(num - 10 + 'A'); 
} 
  
// Utility function to reverse a string ~ Roshan
void strev(char *str) 
{ 
    int len = strlen(str); 
    int i; 
    for (i = 0; i < len/2; i++) 
    { 
        char temp = str[i]; 
        str[i] = str[len-i-1]; 
        str[len-i-1] = temp; 
    } 
} 
  
// Function to convert a given decimal number 
// to a base 'base' and ~ Roshan
char* fromDeci(char res[], int base, int inputNum) 
{ 
    int index = 0;  // Initialize index of result 
  
    // Convert input number is given base by repeatedly 
    // dividing it by base and taking remainder 
    while (inputNum > 0) 
    { 
        res[index++] = reVal(inputNum % base); 
        inputNum /= base; 
    } 
    res[index] = '\0'; 
  
    // Reverse the result 
    strev(res); 
  
    return res; 
} 

int main(){
  int intialNum;
  int intialBase;
  int intialBaseOption;
  int finalNum;
  int finalBase;
  int finalBaseOption;
  int option = 1;
  int base;
  char res[100];

  while (option == 1){

    cout << "(1)Decimal" << endl;
    cout << "(2)Binary" << endl;
    cout << "(3)Octal" << endl;
    cout << "(4)Hexadecimal" << endl;
    cout << "What is the intial value's BASE?" << endl;
    cin >> intialBaseOption;

    cout << "What is the value you want to convert?" << endl;
    cin >> intialNum;

    cout << "(1)Decimal" << endl;
    cout << "(2)Binary" << endl;
    cout << "(3)Octal" << endl;
    cout << "(4)Hexadecimal" << endl;
    cout << "What is the BASE you want to convert(final value)?" << endl;
    cin >> finalBaseOption;

    //the intial value is decimal
    if(intialBaseOption == 1){
      //decimal --> ?
      switch(finalBaseOption){
        // decimal -> decimal
        case 1:
          cout << intialNum << endl;
          cout << "THE INPUT AND OUTPUT BASES ARE THE SAME!!" << endl; 
          break;

        // decimal -> binary
        case 2:
          base = 2; 
          printf("Equivalent of %d in base %d is "
           " %s\n", intialNum, base, fromDeci(res, base, intialNum));
          break;

        // decimal -> octal
        case 3:
          base = 8; 
          printf("Equivalent of %d in base %d is "
           " %s\n", intialNum, base, fromDeci(res, base, intialNum));
          break;

        // decimal -> hexadecimal
        case 4:
          base = 16; 
          printf("Equivalent of %d in base %d is "
           " %s\n", intialNum, base, fromDeci(res, base, intialNum));
          break;
      }
    //the intial value is binary
    } else if (intialBaseOption == 2){
      //binary --> ?
      switch(finalBaseOption){
        // binary -> decimal
        case 1:
          // ~ ANGELO INT TO CHAR PART
          break;

        // binary -> binary
        case 2:
          cout << intialNum << endl;
          cout << "THE INPUT AND OUTPUT BASES ARE THE SAME!!" << endl; 
          break;

        // binary -> octal
        case 3:
          break;

        // binary -> hexadecimal
        case 4:
          break;
      }
    //the intial value is octal
    } else if (intialBaseOption == 3){
      //octal --> ?
      switch(finalBaseOption){
        // octal -> decimal
        case 1:
          // ~ ANGELO INT TO CHAR PART
          break;

        // octal -> binary
        case 2:
          break;

        // octal -> octal
        case 3:
          cout << intialNum << endl;
          cout << "THE INPUT AND OUTPUT BASES ARE THE SAME!!" << endl; 
          break;

        // octal -> hexadecimal
        case 4:
          break;
      }
    //the intial value is hexadecimal
    } else if (intialBaseOption == 4){
      //hexadecimal --> ?
      switch(finalBaseOption){
        // hexadecimal -> decimal
        case 1:
          // ~ ANGELO INT TO CHAR PART
          break;

        // hexadecimal -> binary
        case 2:
          break;

        // hexadecimal -> octal
        case 3:
          break;

        // hexadecimal -> hexadecimal
        case 4:
          cout << intialNum << endl;
          cout << "THE INPUT AND OUTPUT BASES ARE THE SAME!!" << endl; 
          break;
      }
    }

    cout << "Do you want to covert AGAIN?" << endl;
    cout << "(0)EXIT" << endl;
    cout << "(1)CONTIUNE" << endl;
    cin >> option;

  }
  
  return 0;
}



// // function to binary to decimal~Angelo.
// int binaryToDecimal(int n)//p determines 2, 8, 16
// {
//     int num = n;
//     int dec_value = 0;
 
//     // Initializing base value to 1, i.e 2^0
//     int base = 1;
 
//     int temp = num;
//     while (temp) {
//         int last_digit = temp % 10;
//         temp = temp / 10;
 
//         dec_value += last_digit * base;
 
//         base = base * 2;
//     }
 
//     return dec_value;
// }

// Function to convert hexadecimal to decimal ~ Angelo
// int hexadecimalToDecimal(string hexVal) 
// {    
//     int len = hexVal.length(); 
      
//     // Initializing base value to 1, i.e 16^0 
//     int base = 1; 
      
//     int dec_val = 0; 
      
//     // Extracting characters as digits from last character 
//     for (int i=len-1; i>=0; i--) 
//     {    
//         // if character lies in '0'-'9', converting  
//         // it to integral 0-9 by subtracting 48 from 
//         // ASCII value. 
//         if (hexVal[i]>='0' && hexVal[i]<='9') 
//         { 
//             dec_val += (hexVal[i] - 48)*base; 
                  
//             // incrementing base by power 
//             base = base * 16; 
//         } 
  
//         // if character lies in 'A'-'F' , converting  
//         // it to integral 10 - 15 by subtracting 55  
//         // from ASCII value 
//         else if (hexVal[i]>='A' && hexVal[i]<='F') 
//         { 
//             dec_val += (hexVal[i] - 55)*base; 
          
//             // incrementing base by power 
//             base = base*16; 
//         } 
//     } 
      
//     return dec_val; 
// } 

// int decimalToBinary(int N) 
// { 
  
//     // To store the binary number 
//     int B_Number = 0; 
//     int cnt = 0; 
//     while (N != 0) { 
//         int rem = N % 2; 
//         int c = pow(10, cnt); 
//         B_Number += rem * c; 
//         N /= 2; 
  
//         // Count used to store exponent value 
//         cnt++; 
//     } 
  
//     return B_Number; 
// } 

/*
// Function to convert decimal -> binary ~ Roshan
string decimalToBinary(int n) 
{ 
    // array to store binary number 
    int binaryNum[32]; 
    string result = "";
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--){ 
        int x = binaryNum[j];
        string res = to_string(x);
        result = result + res;
    }
    return result;    
} 

// Function to convert hexadecimal -> binary ~ Roshan
string hexadecimalToBinary(string hexdec)
{
    long int i = 0;
    string result = "";
    while (hexdec[i]) {
 
        switch (hexdec[i]) {
        case '0':
            // cout << "0000";
            result = result + "0000";
            break;
        case '1':
            // cout << "0001";
            result = result + "0001";
            break;
        case '2':
            // cout << "0010";
            result = result + "0010";
            break;
        case '3':
            // cout << "0011";
            result = result + "0011";
            break;
        case '4':
            // cout << "0100";
            result = result + "0100";
            break;
        case '5':
            // cout << "0101";
            result = result + "0101";
            break;
        case '6':
            // cout << "0110";
            result = result + "0110";
            break;
        case '7':
            // cout << "0111";
            result = result + "0111";
            break;
        case '8':
            // cout << "1000";
            result = result + "1110";
            break;
        case '9':
            // cout << "1001";
            result = result + "1001";
            break;
        case 'A':
        case 'a':
            // cout << "1010";
            result = result + "1010";
            break;
        case 'B':
        case 'b':
            // cout << "1011";
            result = result + "1011";
            break;
        case 'C':
        case 'c':
            // cout << "1100";
            result = result + "1100";
            break;
        case 'D':
        case 'd':
            // cout << "1101";
            result = result + "1101";
            break;
        case 'E':
        case 'e':
            // cout << "1110";
            result = result + "1110";
            break;
        case 'F':
        case 'f':
            // cout << "1111";
            result = result + "1111";
            break;
        default:
            cout << "";
            // cout << "\nInvalid hexadecimal digit "
            //      << hexdec[i];
        }
        i++;
    }
    return result;
}


// Function to convert octal number to decimal~Angelo
int octalToDecimal(int octalNumber)
{
    int decimalNumber = 0, i = 0, rem;
    while (octalNumber != 0)
    {
        rem = octalNumber % 10;
        octalNumber /= 10;
        decimalNumber += rem * pow(8, i);
        ++i;
    }
    return decimalNumber;
}

void binaryToHex(int binaryNumber)
{
  int hex[1000];
  int i = 1, j = 0, rem, dec = 0;

  while (binaryNumber > 0) 
  {
   rem = binaryNumber % 2;
   dec = dec + rem * i;
   i = i * 2;
   binaryNumber = binaryNumber / 10;
  }
   i = 0;
  while (dec != 0) 
  {
   hex[i] = dec % 16;
   dec = dec / 16;
   i++;
  }
  
  //hex calculation
  for (j = i - 1; j >= 0; j--)
  {
   if (hex[j] > 9) 
   {
    cout<<(char)(hex[j] + 55);
   } 
   else
   {
    cout<<hex[j];
   }
  }
}

int decimalToOctal(int dNum){ //~Brian
  int r, placeV = 1, oNum = 0;
  while (dNum != 0){
    r = dNum % 8; //get remainder
    dNum /= 8; // set decimalNumber to divided value
    oNum += r * placeV; //sets remainder in placeValue position for final result
    placeV *= 10; //increase placeValue for next remainder position
  }
  return oNum; //return final result
}


int binaryToOctal(string bstr){ //~Brian
    int placeV = 1, binAns = 0, octPlace = 0;
    
    int runs = (bstr.length() / 3) + (bstr.length() % 3); //figure out loop runs
    for(int j = 0; j < runs; j++){
        while(bstr.length() < 3){ //incase less than 3 bin places
            bstr = "0" + bstr; //append zero to front
        }
        string bin3 = bstr.substr(bstr.length() - 3); //grabbing last 3 binary spots
        if(bin3[bin3.length()-1] == '1'){ //adding up binary
            octPlace += 1;
        }
        if(bin3[bin3.length()-2] == '1'){ //adding up binary
            octPlace += 2;
        }
        if(bin3[bin3.length()-3] == '1'){ //adding up binary
            octPlace += 4;
        }
        binAns += octPlace * placeV; //setting binary answer by place
        placeV = placeV * 10; //increasing place value/pos
        octPlace = 0; //resetting octal value to add in place pos
        for(int i = 0; i < 3; i++){
            bstr.pop_back(); //deleting used binary spots (back 3)
        }
    }
    return binAns; //return final answer
}

int HexToOctal(string HexNum){ //~Brian 
    string binary = hexadecimalToBinary(HexNum);
    int converted = binaryToOctal(binary);
    
    return converted; //return final answer
}

// Function to convert octal -> binary 
int OctalToBinary(int oNum) { //~Brian
   int dNum = octalToDecimal(oNum); //convert octal to decimal 
   //int dNum = toDeci(n, int base)
   int r, placeV = 1, bNum = 0;
   while (dNum != 0) {
      r = dNum % 2; //get remainder of decimal /2
      dNum /= 2; //set decimalNumber to new value
      bNum += r * placeV; //set remainder in placeValue position for final result
      placeV *= 10; //increase placeValue for next remainder position
   }
   return bNum; //return final result
}

*/
/****

int main() {
  int numConversions;
  int subconversions;
  //num has to be string as hex values can be letters.
  string num;
  int num2;
  cout << "Welcome!" << endl; //greeting1 in mips .data
  //cout << "Please enter a number for the number of conversions to be made:";//numberOfConversions in mips .data
  cout << "How many number do you want converted?" << endl;
  cin >> numConversions;
  
  cout << "Please enter your values to be converted." << endl; // greeting2 in mips .data 

  //make a loop to account for the number of conversions input by the user. ~Angelo
  int counter = 1;
  
  for(int i = 0; i < numConversions; i++){
    cout << "value " << counter << ": ";
    cin >> num;
    int typeEntered = 0;
    cout << "what form is the number that was entered?" << endl;
    cout << "(1)Decimal" << endl;
    cout << "(2)Binary" << endl;
    cout << "(3)Octal" << endl;
    cout << "(4)Hexadecimal" << endl;

    cin >> typeEntered;

    cout << "How many different conversions do you want to make with this value?" << endl;
    cin >> subconversions;
    cout << "Here are your options: " << endl;
    cout << "(1)Decimal" << endl;
    cout << "(2)Binary" << endl;
    cout << "(3)Octal" << endl;
    cout << "(4)Hexadecimal" << endl;

    int type = 0;

    //second loop for sub conversions.
  for(int j = 0; j < subconversions; j++){
      cin >> type;
      if(type == 1){
        //decimal conversion function.~ Angelo.
        //IMPORTANT: num2 is num as an integer, num is a string.
        num2 = stoi(num);
        if(typeEntered == 2){
          cout << "Decimal value: ";
          //num2 = stoi(num);
          //cout << binaryToDecimal(num2) << endl;
          cout << toDeci(num, 2) << endl;
        }
        if(typeEntered == 1){
          cout << "Decimal value: " << num << endl;
        }
        if(typeEntered == 4){
          cout << "Decimal value: ";
          //cout << hexadecimalToDecimal(num) << endl;
          cout << toDeci(num, 16) << endl;
        }
        if(typeEntered == 3){
          cout << "Decimal value: ";
          //num2 = stoi(num);
          //cout << octalToDecimal(num2) << endl;
          cout << toDeci(num, 8) << endl;
        }
  
      }

      if(type == 2){
        //binary conversion function.
        //IMPORTANT: num2 is num as an integer, num is a string.
        num2 = stoi(num);
        //char num3 = '0' + num;
        //binary -> binary ~ Roshan
        if(typeEntered == 2){
          cout << "Binary value: " << num2 << endl;
        }
        //decimal -> binary ~ Roshan
        if(typeEntered == 1){
          cout << "Binary value: " << decimalToBinary(num2) << endl;
        }
        //hexadecimal -> binary ~ Roshan
        if(typeEntered == 4){
          cout << "Binary value: ";
          hexadecimalToBinary(num);
          cout << endl;
        }
        //octal -> binary ~ Roshan
        if(typeEntered == 3){
          cout << "Binary value: " << OctalToBinary(num2) << endl;
        }
      }  

      if(type == 4){
        //hexadecimal conversion function.~Jonathan
        //IMPORTANT: num2 is num as an integer, num is a string.
        num2 = stoi(num);
        // if(type != typeEntered){
        //     num2 = stoi(num);
        // }

        //binary -> hexadecimal
        if(typeEntered == 2){
          cout << "Hexadecimal value: ";
          binaryToHex(num2);
          cout << endl;
        }
        //decimal -> hexadecimal
        if(typeEntered == 1){
          cout << "Hexadecimal value: ";
          
          string temp = decimalToBinary(num2);
          int temp2 = stoi(temp);
          binaryToHex(temp2);
          cout << endl;
          
        }
        //hexadecimal -> hexadecimal // cout entered 
        if(typeEntered == 4){
            cout << "Hexadecimal value: ";
            cout << num;
            cout << endl;
        }
        //octal -> hexadecimal 
        if(typeEntered == 3){
            cout << "Hexadecimal value: ";
            int n3 = OctalToBinary(num2);
            binaryToHex(n3);

            cout << endl;
        }
      }
      if(type == 3){
        num2 = stoi(num);
        //IMPORTANT: num2 is num as an integer, num is a string.
        //octal conversion function.~Brian
        //binary -> octal
        if(typeEntered == 2){
          cout << "Octal value: ";
          cout << binaryToOctal(num) << endl;
        }
        //decimal -> octal
        if(typeEntered == 1){
          cout << "Octal value: ";
          cout << decimalToOctal(num2) << endl;
        }
        //hexadecimal -> octal
        if(typeEntered == 4){
          cout << "Octal value: ";
          cout << HexToOctal(num) << endl;
        }
        //octal -> octal // cout entered value, no calculation needed.
        if(typeEntered == 3){
          cout << "Octal value: " << num << endl;
        }
        //num is the value being entered in.
      }


    }


    counter++;
  }


}
*/

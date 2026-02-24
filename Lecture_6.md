LECTURE 6

# FILE IO





**const //a type qualifier**



const int x = i;

x++; //ERROR, variable x is constant





int x = 1;



const int\* p = \&x;



p = NULL;



\*p = 2; //ERROR, TRYING TO CHANGE VALUE



x = 3; //okay



Int is const, star is not const





const type is typically before it, if nothing before, then after



int\* const p = \&x;



p = NULL; //ERROR



p\* = 10; //okay



x = 3; //okay





const int\* const p = \&x



both int and \* are 'constant' now







int const \*\*p = \&q;



\*\*p = 10;









string.h



char arr\[] = {'x', '?', ' ', 'y', '!', '\\0', 'z', '\\0'}





char new\_arr\[6];



strcpy(new\_arr, arr); //copy a sting, first argument destination, second argument source



strlen(arr); //arr





>= strln(arr) + 1 to account for NULLS



SOURCE STRING AND DESTINATION STRING MUST NOT SHARE OVERLAPPING MEMORY REGIONS





**strcmp**



char\_new\_arr\[6];



strcpy(new\_arr, arr);



int x = strcmp(arr, new arr); //0 which means these are identical



if different, strcmp will return a negative value. less than = negative

greater than = positive.







**strstr** //find the first ococurrence ofa substring in a string



char\* p = strstr(arr, "? ");



printf("%s", p); // ->>>> "? y!" //p is holding first occurence of char specified and goes until it hits first null





char arr\[] = "1111abcxyz"

long x = strtol(arr, NULL, 10); //third value is 'base', will assign variable all values in sequence that match "base"



printf("%ld", x);



The second argument holds the remaining constants







 



**strdup**

//Create dynamically allocated copy of a string: malloc + strcpy



char arr1\[] = "hello";



char\* arr2 == strdup(arr1);



arr2\[0] = 'H';



printf("%s", arr1); //"hello"



printf("%s"); //"Hello" value in first index was swappped for 'H'







void function(){

 

 char arr1\[] = something; mutable

 char\* arr2 = something; //this is in data segment and immutable, (read only), different segment when "pointing"



}







fopen int main(int argc, char\*\* argv) //AMOUNT OF COMMAND LINE ARGUMENTS, STRINGS OF COMMAND LIND ARGUMENTS (int and char)

{



 if (argc != 2) return EXIT\_FAILURE

 FILE\* fp = fopen(argv\[1], "w"); //fopen is used to open a file "argv\[1]" -> file name to be opened

 //"w" -> erase and write | "a" -> append and write | "r" -> read

 //"w+" -> if file does not exist, creates new |"r+" -> file must exist | "a+" -> | all for read and write

 

 //FILE is a user defined data type





fprintf(fp, "%d\\n", 10); print something in file

fclose(fp); //when opening a file, always close the file
once you close the file, dont not use fp

}







fgetc //used to read a character



int ch;

while((ch = fgetc(fp)) != EOF) {

//EOF is "end of file" or typically -1

//this while loop will read each character of the file sequentially until reaching EOF

//you can then printf("%c", ch);



}



**EXAMPLE 2 feof**





int ch;

while((ch = fgetc(fp)) != EOF) {

 ...

}

if(feof(fp)) {

 //normal end of file

}

else if(ferror(fp)) {

 //error occured

}





**WHAT YOU SHOULDNT DO WITH FEOF**

int ch;

while(!feof(fp)))) {

 ch = fgetc(fp)

 //this will return a non-zero, AFTER fgetc sets EOF flag

}



**fscanf** //want to read a integer value from a file



int val;

 while(fscanf(fp, %d", \&val) == 1) { //NOT 0 because if != 0 then wont catch EOF which is = -1

 printf("%d\\n", val);



}



char arr\[6];



while(fscanf(fp, "%5s", arr) == 1) {

 printf("%s", arr);



}


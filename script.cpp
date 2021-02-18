#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include <cmath>
using namespace std;
using namespace cgicc;

#define DEPTH 4

using namespace std;

string textConvertation(string text);
int howManyWordsTextHas(string text);
void fillingArray(string text, string array[]);
double calculatingPercentageOfPlagiarism(string sourceTextArray[], string verifiableTextArray[], int sizeOfSourceText, int sizeOfVerifiableArray);
void printIntro();
void printPercentage(double percentage);
double antiPlagiarism(string text, string fragment);

//int getInt(string name);//get length of text putted in the form on your site(this function we use only for example)
string getDB();//get origin text from db.txt (don't modify tis function)

int main()
{
    

	Cgicc form;
    string name;

    cout << "Content-type:text/html\r\n\r\n";
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<title>Ggi Server</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";
    cout << "<p>";
    
    name = form("name");
    if (!name.empty()) {
    	cout << antiPlagiarism(getDB(), name) << "\n";
    } else {
    	cout << "Text is not provided!\n";
    }	
    cout << "</p>\n";
    cout << "</body>\n";
    cout << "</html>\n";

    return 0;
}

string getDB(){
	std::ifstream in("db.txt");

    string dbText = "", s1;
    while (getline(in, s1))
    	dbText += s1;
  
    in.close();
    
    return dbText;
}

double antiPlagiarism(string sourceText, string verifiableText) {
	printIntro();
	
	
	sourceText = textConvertation(sourceText);
	verifiableText = textConvertation(verifiableText);
	
	int amountOfWordsInSourceText = howManyWordsTextHas(sourceText);
	int amountOfWordsInVerifiableText = howManyWordsTextHas(verifiableText);
	
	string sourceTextArray[amountOfWordsInSourceText];
	string verifiableTextArray[amountOfWordsInVerifiableText];
	
	fillingArray(sourceText, sourceTextArray);
	fillingArray(verifiableText, verifiableTextArray);
	
	double percentageOfPlagiarism = calculatingPercentageOfPlagiarism(sourceTextArray, verifiableTextArray, amountOfWordsInSourceText, amountOfWordsInVerifiableText);
	
	printPercentage(percentageOfPlagiarism);
	return round((100-percentageOfPlagiarism)*100/100);

}

string textConvertation(string text){
	string temp;
	
	//ASCII 
	for(int i = 0; i < text.size(); i++){
		if(text[i] == ' '){
			temp += ' ';
		}else if(text[i] >= 65 and text[i] <= 90){
			temp += (text[i] + 32);
		}else if((text[i] >= 48 and text[i] <= 57) or (text[i] >= 97 and text[i] <= 122)){
			temp += text[i];
		}
	}
	
	return temp;
}

int howManyWordsTextHas(string text){
	int counter = 1;
	
	for(int i = 0; text[i] != '\0'; i++){
		if(text[i] == ' '){
			counter++;
		}
	}
	
	
	return counter;
}

void fillingArray(string text, string array[]){
	int wordsCounter = 0;
	string word;
	
	for(int i = 0; i <= text.size(); i++){
		if(text[i] == ' ' or (i == text.size())){
			array[wordsCounter] = word;
			wordsCounter++;
 			word = "";
		}else{
    		word += text[i];
    	}
	}
}

double calculatingPercentageOfPlagiarism(string sourceTextArray[], string verifiableTextArray[], int sizeOfSourceText, int sizeOfVerifiableText){
	int allSelections = 0, plagiatedSelections = 0;
	int stepForSourceText = 0, stepForVerifiableText = 0;
	string tempForSourceText, tempForVerifiableText;
	
	for(int i = 0; i < ((sizeOfVerifiableText - DEPTH) + 1); i++){
		for(int j = 0; j < ((sizeOfSourceText - DEPTH) + 1); j++){
			for(int k = 0; k < DEPTH; k++){
				tempForVerifiableText += verifiableTextArray[k + stepForVerifiableText];
				tempForSourceText += sourceTextArray[k + stepForSourceText];
			}

			if(tempForVerifiableText == tempForSourceText){
				plagiatedSelections++;
				
				tempForVerifiableText = "";
				tempForSourceText  = "";
			
				break;
			}
			
			stepForSourceText++;
			tempForVerifiableText = "";
			tempForSourceText  = "";
		}
		allSelections++;
		stepForVerifiableText++;
		stepForSourceText = 0;
	}

	return (plagiatedSelections * 100.00) / allSelections;
	
}

void printIntro(){
	//cout << "Hello, user! This program helps to calculate the percentage of plagiarism." << endl << endl;
}

void printPercentage(double percentage){
	//cout << endl << "Plagiarism percentage: " << percentage << "%";
}

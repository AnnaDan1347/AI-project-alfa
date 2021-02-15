#include <iostream>
#include <cstring>
#include <cstdlib>

#define DEPTH 4

using namespace std;

string textConvertation(string text);
int howManyWordsTextHas(string text);
void fillingArray(string text, string array[]);
double calculatingPercentageOfPlagiarism(string sourceTextArray[], string verifiableTextArray[], int sizeOfSourceText, int sizeOfVerifiableArray);
void printIntro();
void printPercentage(double percentage);
double antiPlagiarism(string text, string fragment);

int main(){

	string sourceText, verifiableText;
	double antiPlagiarism(string sourceText, string verifiableText);
	
	
	
	
	return 0;
}

double antiPlagiarism(string text, string fragment) {
	printIntro();
	
	cout << "Input your source text: ";
	getline(cin, sourceText);
	
	cout << endl << "Input your text for checking: ";
	getline(cin, verifiableText);

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

};

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
		if(text[i] == ' '){#include <iostream>
#include <cstring>
#include <cstdlib>

#define DEPTH 2

using namespace std;

string textConvertation(string text);
int howManyWordsTextHas(string text);
void fillingArray(string text, string array[]);
double calculatingPercentageOfPlagiarism(string sourceTextArray[], string verifiableTextArray[], int sizeOfSourceText, int sizeOfVerifiableArray);
void printIntro();
void printPercentage(double percentage);
double antiPlagiarism(string text, string fragment);

int main(){

	string sourceText, verifiableText;
	cout << "Input your source text: ";
	getline(cin, sourceText);
	
	cout << endl << "Input your text for checking: ";
	getline(cin, verifiableText);

	cout << antiPlagiarism(sourceText, verifiableText);
	
	
	
	
	return 0;
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

};

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
	
	if(counter < DEPTH){
		cout << "You inputed too short string!" << endl;
		
		return - 1;
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
	cout << "Hello, user! This program helps to calculate the percentage of plagiarism." << endl << endl;
}

void printPercentage(double percentage){
	cout << endl << "Plagiarism percentage: " << percentage << "%";
}

			counter++;
		}
	}
	
	if(counter < DEPTH){
		cout << "You inputed too short string!" << endl;
		
		return - 1;
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
	cout << "Hello, user! This program helps to calculate the percentage of plagiarism." << endl << endl;
}

void printPercentage(double percentage){
	cout << endl << "Plagiarism percentage: " << percentage << "%";
}

## [AI-Project](https://github.com/vladz-ostr/AI-Project/blob/main/AI.BetaVersion.cpp)


In this project, we have implemented the <b> Anti-Plagiarism </b> mechanism.
The basic principle of the algorithm is to compare combinations of several words.
We came to the conclusion that the most accurate result is obtained by taking 4 words for comparison.
Stack of technologies that we were using during the project:
- C++
- HTML/CSS

Project has been made by:


<b>Vladislav Ostrovsky</b>: <i>vladzislav.ostrovsky@gmail.com </i>

 and

<b>Anna Danilenko</b>: <i>ganna.danilenka@gmail.com </i>






<hr>

The amount of words to compare
```c++
#define DEPTH 4
```
<hr>

Initialize variables and getting data
```c++
string text;

cout << "Input your text: ";
getline(cin, text);
```
<hr>

Use a function to lowercase text and remove punctuation and special characters
```c++
text = textConvertation(text);
```
<i>The principle of the algorithm - checking for ASCII values</i>

<hr>

Сalculate the amount of words in the entered text
```c++
int amountOfWordsInText = howManyWordsTextHas(text);
```
<i>The principle of the algorithm - calculating spaces between words</i>

<hr>

Initialize arrays for storing words with the dimension obtained from ```howManyWordsTextHas(text)```
```c++
string textArray[amountOfWordsInText];
```

<i>The principle of the algorithm - сharacter-by-character check up to a space</i>
<hr>

Сalculate the percentage by comparing the number of plagiated samples to all
```c++
double percentageOfPlagiarism = calculatingPercentageOfPlagiarism();
```
<i>The principle of the algorithm:

- There are two starting points for 2 texts at the begin of the arrays
- Filling <b> temp </b> strings with amount of words that equals <b> DEPTH </b>
- Compare strings. If strings are equals - incrementing counter for plagiated selections and breaking the loop. if not - continue 
- After every check increase <b> source step </b> value to move on to the next selections
- After source string has been successfully checked increase <b> verifiable step </b> value and starting over again
- In the end return the value by ```return (plagiatedSelections * 100.00) / allSelections;```
</i>



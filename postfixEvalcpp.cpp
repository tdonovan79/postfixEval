//Evaluate postfix expressions entered by user as strings using stacks.
//Thomas Donovan
//4/3/19
#include<iostream>
#include<string>
#include"LinkedStack.h"
#include"Node.h"

int evaluateString(std::string);
bool isInt(char);
void operatorChecker(char, LinkedStack<int>&);
void assignVal(int&, LinkedStack<int>&);
void addition(LinkedStack<int>&);
void subtraction(LinkedStack<int>&);
void multiplication(LinkedStack<int>&);
void division(LinkedStack<int>&);
void modulus(LinkedStack<int>&);

int main(){
	//get postfix string
	std::string postfixEntry;
	std::cout << "Enter a postfix expression, seperating values with $: ";
	std::cin >> postfixEntry;
	//evaluate and output result
	std::cout << "Answer: " << evaluateString(postfixEntry);
	
	
	return 0;
}
//evaluate the postfix expression
int evaluateString(std::string postfixEntry)
{
	//create stack for the ints
	LinkedStack<int> IntStack;
	//create a string to hold pieces of entered string
	std::string holder;
	//iterate through characters in string
	for(int i = 0 ; i < (postfixEntry.size()); i++)
	{
		//check to see if current character is an operator, if so, evaulate the expression
		operatorChecker(postfixEntry[i], IntStack);		

		//if current character is an int add it to holding string
		if(isInt(postfixEntry[i]))
		{
			holder += postfixEntry[i];
		}
		
				
		//if current charactor is $, push holder to stack if there's anything in it, flush holder string 
		//and continue to next iteration
		if(postfixEntry[i] == '$')
		{
			if(!holder.empty())
			{
				IntStack.push(stoi(holder));
			}
			holder.clear();
		}
		
	}
	//return result on top of stack
	return IntStack.peek();
}

//check to see if character is an operator, if it is, evaluate expression
void operatorChecker(char stringSeg, LinkedStack<int>& IntStack)
{
	//check to see if character is an operator, if so perform the operation
	if(stringSeg == '+')
		addition(IntStack);
	if(stringSeg == '-')
		subtraction(IntStack);
	if(stringSeg == '*')
		multiplication(IntStack);
	if(stringSeg == '/' )
		division(IntStack);
	if(stringSeg == '%')
		modulus(IntStack);
	
}
//check if char is a single digit int
bool isInt(char testChar)
{
	bool flag = false;
	for(int i = 0 ; i < 10 ; i++)
	{
		if((testChar - 48) == i)
			flag = true;
	}
	return flag;
}

//assign value of top int on stack and then pop off stack
void assignVal(int& val, LinkedStack<int>& IntStack)
{
	val = IntStack.peek();
	IntStack.pop();
}

//perform addition on top two values in stack, push result onto stack
void addition(LinkedStack<int>& IntStack)
{
	int leftHandVal, rightHandVal, sum;
	assignVal(rightHandVal, IntStack);
	assignVal(leftHandVal, IntStack);
	sum = leftHandVal + rightHandVal;
	IntStack.push(sum);
}

//perform subtraction on two values in stack, and push result onto stack
void subtraction(LinkedStack<int>& IntStack)
{
	int leftHandVal, rightHandVal, difference;
	assignVal(rightHandVal, IntStack);
	assignVal(leftHandVal, IntStack);
	difference = leftHandVal - rightHandVal;
	IntStack.push(difference);
}

//perform multiplication on two values in stack, and push result onto stack
void multiplication(LinkedStack<int>& IntStack)
{
	int leftHandVal, rightHandVal, product;
	assignVal(rightHandVal, IntStack);
	assignVal(leftHandVal, IntStack);
	product = leftHandVal * rightHandVal;
	IntStack.push(product);
}

//perform division on two values in stack, and push result onto stack
void division(LinkedStack<int>& IntStack)
{
	int leftHandVal, rightHandVal, quotient;
	assignVal(rightHandVal, IntStack);
	assignVal(leftHandVal, IntStack);
	quotient = leftHandVal / rightHandVal;
	IntStack.push(quotient);
}

//perform modulus on two values in stack, and push result onto stack
void modulus(LinkedStack<int>& IntStack)
{
	int leftHandVal, rightHandVal, remainder;
	assignVal(rightHandVal, IntStack);
	assignVal(leftHandVal, IntStack);
	remainder = leftHandVal % rightHandVal;
	IntStack.push(remainder);
}



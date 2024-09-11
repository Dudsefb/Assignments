/* This is a small training program to kickstart my C++ practice.
 * It receives the number of Hours, Minutes and Seconds and
 * converts it to seconds only.
 */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//Removes all whitespace from a string
void trimWhitespace(string& str){
	unsigned int id = 0;
	for(string::iterator it=str.begin();it!=str.end();++it)
		if(*it!=' ') str[id++] = *it;
	str.erase(id);
}

//Converts all applicable characters to upper case
void toUpper(string& str){
	for(string::iterator it=str.begin();it!=str.end();++it)
		if(*it>96&&*it<173) *it -= 32;
}

//Checks if the string contains any of the specified markers
bool hasMarker(const string str){
	return  str.find_first_of('H')!=string::npos ||
		str.find_first_of('M')!=string::npos ||
		str.find_first_of('S')!=string::npos;
}

//Checks if the string contains any number
bool hasNumber(const string str){
	for(string::const_iterator it=str.cbegin();it!=str.cend();++it)
		if(*it>47&&*it<58) return true;
	return false;
}

//Extracts the value from the string
unsigned int getValue(const string str, const char ref){
	size_t id1 = str.find_first_of(ref)-1;
	unsigned short counter = 0;
	unsigned int ans=0; 
	while(str[id1]>47&&str[id1]<58)
		ans += (((int)str[id1--])-48)*pow(10,counter++);
	return ans;
}

//Converts the pre-formatted string to seconds
unsigned int timeToSeconds(const string str){
	unsigned int h = 0, m = 0, s = 0;
	//Transfers the values from the input
	h = getValue(str,'H');
	m = getValue(str,'M');
	s = getValue(str,'S');
	return h*3600+m*60+s;
}

int main(){

	//Variable declaration
	string header = "--------------------------------\n";
	header += "    Hour to Second converter     \n";
	header += "--------------------------------\n\n";
	header += " > Insert the time as xxh xxm xxs and press Enter \n";
	header += " > When you're done, insert Q and press Enter \n"; //Standard message displayed at startup
	string buffer; //A buffer to store the user input
	vector<unsigned int> seconds; //A vector to store the answers
	unsigned int counter = 0; //A general-purpose counter
	
	//Beginning of the program
	cout << header;
	while(true){
		//Adds an indication of the number of the current entry
		cout << " " << counter+1 << " - ";
		//Reads it to the buffer
		getline(cin,buffer);
		//Removes all white space
		trimWhitespace(buffer);
		//Converts all characters to upper case
		toUpper(buffer);
		//Exit condition
		if(buffer[0]==81) break;
		//Checks if the input is valid
		if(buffer[0]=='\0') continue;
		if(!hasMarker(buffer)) continue;
		if(!hasNumber(buffer)) continue;
		//Adds the value to a vector
		seconds.push_back(timeToSeconds(buffer));
		//Increments the counter
		counter++;
	}
	//Prints the results onto the console
	cout << " > Results:\n";
	for(unsigned int i = 0;i<counter;i++)
		cout << " " << i+1 << " - " << seconds[i] << " seconds\n";

	return 0;
}

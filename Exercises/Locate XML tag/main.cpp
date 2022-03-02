#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string find_field(const string &xml, string tag_name);

int main() {
	string page, line, location, temperature;
	ifstream inputFile("weather.xml");
	
	while (getline (inputFile, line)) {
 	    page.append(line);
 	    line.erase();
	}
	location = find_field(page, "location");
	temperature = find_field(page, "temp_c");
	// Now page is a string that contains the whole xml page
	
	// Here you need to write something that finds and 
	// extracts location and temperature from the XML
	// data in the string page and stores them in 
	// the strings location and temperature respectively
	
	cout << "Location: " << location << endl;
	cout << "Temperature: " << temperature << endl; 
	
}


string find_field(const string &xml, string tag_name)
{
	bool read(false);
	string tag1, tag2;
	tag1 = "<" + tag_name + ">";
	size_t start = xml.find(tag1);
	size_t end;
	if (start != string::npos) {
		start += tag1.length();
		read = true;
	}
	if (read) {
		tag2 = "</" + tag_name + ">";
		end = xml.find(tag2);
		if (end != string::npos) {
			return xml.substr(start, end - start);
		}
	}
	// construct start and end tags from from the tag name 
	// add angle brackets to both tags and also slash to end tag
	// then search for tags 
	// if both are found then return the substring between the tags
	
	return "not found"; // return this if tag is not found
}

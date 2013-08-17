#include <iostream>
#include <fstream>
using namespace std;

int main()
    {
	string line,line2;
	
	ifstream ifile ("X-axis.txt");
	ofstream ofile;
        ifstream ifile2 ("Y-axis.txt"); 
	ofile.open ("output.txt");

  	if (ifile.is_open() && ifile2.is_open())
  	    {
		int i = 0;
    		while ( !ifile.eof() && !ifile.eof())
    		    {
      			getline (ifile,line);
			getline(ifile2,line2);
		ofile << line << "\t" << line2 << endl;
		//    			i++;
		    }
    		ifile.close();
		ifile2.close();
  	    }
 
	else cout << "Unable to open file"; 
	ofile.close();

	return 0;
    }

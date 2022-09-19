
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
int sizef(std::string name)
{
    std::ifstream fi(name);
    fi.seekg(0, std::ios::end);
    return fi.tellg();
}
int main(int argc, char* argv[]) {
    int l = 0, c = 0, w = 0, m = 0, k = 0, j, i, flag = 0;
    int lnum = 0, cnum, wnum = 0, mnum = 0;
    std:: vector <std::string> file;
    std::ifstream in;
    std::string e;
    for ( i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (argv[i] == "-l" || argv[i] == "--lines")l = 1;
            else if (argv[i] == "-c" || argv[i] == "--bytes")c = 1;
            else if (argv[i] == "-w" || argv[i] == "--words")w = 1;
            else if (argv[i] == "-m" || argv[i] == "--chars")m = 1;
            else {
                e = argv[i];
                for (j = 1; j < e.length(); j++) {
                    if (e[j] == 'l')l = 1;
                    else if (e[j] == 'c')c = 1;
                    else if (e[j] == 'w')w = 1;
                }
            }
        }
        else {
            file.push_back(argv[i]);
        }
    }
    for (i = 0; i < file.size(); i++) {
        lnum = 1;
        wnum = 0;
        mnum = 0;
        cnum = 0;
        in.open(file[i]);
        if(in.is_open()){
            char t;
            flag = 0;
            while (in.get(t)) {
                if (t == '\n') {
                    lnum++;
                }
                if (t != ' ' && flag==0) {
                    flag = 1;
                    wnum++;
                }
                else if (t == ' ' || t=='\n'){
                    flag = 0;
                }
                if ((int(t) >= 65 && int(t) <= 90) || (int(t) >= 97 && int(t) <= 122))mnum++;
            }
            cnum = sizef(file[i]);

            if (l == 0 && c == 0 && w == 0 && m == 0) {
                std::cout << lnum << " " << cnum << " " << wnum << " " << mnum<<std::endl;
            }
            else {
                if (l == 1)std::cout << lnum << " ";
                if (c == 1)std::cout << cnum << " ";
                if (w == 1)std::cout << wnum << " ";
                if (m == 1)std::cout << mnum;
                std::cout<<std::endl;
            }
        }
        else std::cout<<"no such file"<<std::endl;
        in.close();
    }
}


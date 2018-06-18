#include <string>
#include <list>
#include <iostream>
#include <locale>
#include <sstream>
#include <iomanip>

using namespace std;

class cipher {

    public:

        list<int> encrypt(string key,string message)
        {
            return doEncrypt(key,message);
        }

        list<int> encrypt(string key, list<int> message)
        {
            return doEncrypt(key,message);
        }

        wstring decrypt(string key, list<int> message)
        {
            list<int> lst = doEncrypt(key,message);
            wstring retString;
            for(list<int> :: iterator it = lst.begin(); it != lst.end(); it++)
            {
                retString += wchar_t(*it);
            }
            return retString;
        }

        list<int> toAscii(string aString)
        {
            list<int> retlist;
            for(int i = 0; i < aString.length(); i++)
            {
                char c = aString.at(i);
                retlist.push_back(int(c));
            }
            return retlist;
        }

        list<int> doEncrypt(string key, list<int> message)
        {
            int kind = 0;
            list<int> retlist;
            for(list<int>::iterator mit = message.begin(); mit != message.end(); mit++)
            {
                retlist.push_back(key.at(kind++) ^ *mit);
                if(kind >= key.length())
                {
                    kind = 0;
                }
            }
            return retlist;
        }

        list<int> doEncrypt(string key, string message)
        {
            int kind = 0;
            list<int> retlist;
            for(int i = 0; i < message.length(); i++)
            {
                retlist.push_back(message.at(i) ^ key.at(kind++));
                if(kind >= key.length())
                {
                    kind = 0;
                }
            }
            return retlist;

        }

        void showList(list<int> lst,char delim)
        {
            stringstream stream;
            for(list<int> :: iterator it = lst.begin(); it != lst.end(); it++)
            {
                stream << setfill('0') << setw(sizeof(char)*2) << hex << *it << delim;
            }
            stream << "\b \b" << endl;
            cout << stream.str() << endl;
        }

        void showEncryption(list<int> lst)
        {
            for(list<int> :: iterator it = lst.begin(); it != lst.end(); it++)
            {
                wcout << wchar_t(*it);
            }
            cout << endl;
        }

};
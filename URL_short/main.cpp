#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string URL_change(long int n)
{

    char map[] = "abcdefghijklmnopqrstuvwxyzABCDEF"
                 "GHIJKLMNOPQRSTUVWXYZ0123456789";

    string URL;

    while (n)
    {

        URL.push_back(map[n%62]);
        n = n/62;
    }

    reverse(URL.begin(), URL.end());

    return URL;
}

long int URLtoID(string URL)
{
    long int id = 0;


    for (int i=0; i < URL.length(); i++)
    {
        if ('a' <= URL[i] && URL[i] <= 'z')
          id = id*62 + URL[i] - 'a';
        if ('A' <= URL[i] && URL[i] <= 'Z')
          id = id*62 + URL[i] - 'A' + 26;

    }
    return id;
}


int main()
{
    int n = 12345;


    string URL = URL_change(n);
    cout<<"enter the url that you want to make it short :- ";
      cin >> URL;
    cout << "short Id form of url is " << URLtoID(URL);
    return 0;
}

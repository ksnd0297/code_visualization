// https://www.acmicpc.net/problem/5525
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
int n;
int length;
string str;
cin >> n >> length;
cin >> str;


int sCount = 0;

string cStr = "IOI";

if (n != 1)
{
for (int i = 0; i < n - 1; i++)
{
cStr += "OI";
}
}


for (int i = 0; i < length; i++)
{
int count = 0;
for (int j = 0; j < cStr.length(); j++)
{
if (i + j >= str.length())
{
i = length;
break;
}

if (str[i + j] == cStr[j])
{
count++;

if (count == cStr.length())
{
sCount++;
}
}
else
{
break;
}
}

}


cout << sCount << endl;

}